import java.io.BufferedReader
import java.io.BufferedWriter
import java.io.InputStreamReader
import java.io.OutputStreamWriter
import java.util.*

private const val MAX = 100
private val areas = Array(MAX) { CharArray(MAX) }
private val visited = Array(MAX) { BooleanArray(MAX) { false } }
private val dx = listOf(-1, 0, 1, 0)
private val dy = listOf(0, 1, 0, -1)
private var n = 0

fun main(args: Array<String>) = with(BufferedReader(InputStreamReader(System.`in`))) {
    val bw = BufferedWriter(OutputStreamWriter(System.out))
    n = readLine().toInt()

    repeat(n) { row ->
        val input = readLine()
        repeat(n) { col ->
            areas[row][col] = input[col]
        }
    }

    // normal
    var cnt = 0
    repeat(n) { row ->
        repeat(n) { col ->
            if (!visited[row][col]) {
                visited[row][col] = true
                bfs(row, col, false)
                cnt++
            }
        }
    }
    bw.write("$cnt ")

    // color blind
    resetVisited()
    cnt = 0
    repeat(n) { row ->
        repeat(n) { col ->
            if (!visited[row][col]) {
                visited[row][col] = true
                bfs(row, col, true)
                cnt++
            }
        }
    }
    bw.write("$cnt")

    bw.flush()
    bw.close()
}

private fun resetVisited() {
    repeat(n) { row ->
        repeat(n) { col ->
            visited[row][col] = false
        }
    }
}

private fun bfs(startY: Int, startX: Int, isColorBlind: Boolean) {
    val queue: Queue<Pair<Int, Int>> = LinkedList()
    queue.add(Pair(startY, startX))

    while (queue.isNotEmpty()) {
        val currY = queue.peek().first
        val currX = queue.peek().second
        queue.poll()

        repeat(4) {
            val dy = currY + dy[it]
            val dx = currX + dx[it]
            if (dy < 0 || dy >= n || dx < 0 || dx >= n) return@repeat

            if (areas[dy][dx] == areas[currY][currX] && !visited[dy][dx]) {
                visited[dy][dx] = true
                queue.add(Pair(dy, dx))
            } else if (isColorBlind && isRedAndGreen(areas[dy][dx], areas[currY][currX]) && !visited[dy][dx]) {
                visited[dy][dx] = true
                queue.add(Pair(dy, dx))
            }
        }
    }
}

fun isRedAndGreen(char1: Char, char2: Char) = setOf(char1, char2) == setOf('R', 'G')
