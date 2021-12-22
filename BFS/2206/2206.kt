import java.io.BufferedReader
import java.io.BufferedWriter
import java.io.InputStreamReader
import java.io.OutputStreamWriter
import java.util.*

private const val MAX = 1000
fun main(args: Array<String>) = with(BufferedReader(InputStreamReader(System.`in`))) {
    data class Point(val y: Int, val x: Int, val wallLeft: Boolean, var dist: Int)

    val bw = BufferedWriter(OutputStreamWriter(System.out))
    val map = Array(MAX + 1) { BooleanArray(MAX + 1) }
    val visited = Array(MAX + 1) { Array(MAX + 1) { BooleanArray(2) { false } } }
    val dx = listOf(-1, 0, 1, 0)
    val dy = listOf(0, 1, 0, -1)
    var minDist = -1

    val (n, m) = readLine().split(" ").map { it.toInt() }
    repeat(n) { row ->
        val input = readLine()
        repeat(m) { col ->
            map[row][col] = input[col] == '1'
        }
    }

    fun bfs() {
        val queue: Queue<Point> = LinkedList()
        queue.add(Point(0, 0, true, 1))
        visited[0][0][0] = true

        while (queue.isNotEmpty()) {
            val curr = queue.poll()
            if (curr.y == n - 1 && curr.x == m - 1) {
                if (minDist == -1 || curr.dist < minDist) minDist = curr.dist
                continue
            }

            repeat(4) {
                val ny = curr.y + dy[it]
                val nx = curr.x + dx[it]
                if (ny < 0 || ny >= n || nx < 0 || nx >= m) return@repeat

                // 벽이 없고 벽을 안 부수고 왔을 경우
                if (!map[ny][nx] && !visited[ny][nx][0] && curr.wallLeft) {
                    queue.add(Point(ny, nx, curr.wallLeft, curr.dist + 1))
                    visited[ny][nx][0] = true
                } else if (!map[ny][nx] && !visited[ny][nx][1] && !curr.wallLeft) { // 벽이 없고 벽을 부수고 왔을 경우
                    queue.add(Point(ny, nx, curr.wallLeft, curr.dist + 1))
                    visited[ny][nx][1] = true
                } else if (map[ny][nx] && !visited[ny][nx][0] && curr.wallLeft) { // 벽이 있고 벽을 안 부수고 왔을 경우
                    queue.add(Point(ny, nx, false, curr.dist + 1))
                    visited[ny][nx][1] = true
                }
            }
        }
    }

    bfs()
    bw.write("$minDist")

    bw.flush()
    bw.close()
}
