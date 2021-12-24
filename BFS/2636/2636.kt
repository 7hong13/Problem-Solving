import java.io.BufferedReader
import java.io.BufferedWriter
import java.io.InputStreamReader
import java.io.OutputStreamWriter
import java.util.*

private const val MAX = 100

fun main(args: Array<String>) = with(BufferedReader(InputStreamReader(System.`in`))) {
    val bw = BufferedWriter(OutputStreamWriter(System.out))
    val map = Array(MAX) { IntArray(MAX) }
    val dx = listOf(-1, 0, 1, 0 )
    val dy = listOf(0, 1, 0, -1)
    var totalHour = 0
    var cheeseCnt = 0
    var prevCheeseCnt = 0

    val (r, c) = readLine().split(" ").map { it.toInt() }
    repeat(r) { row ->
        val input = readLine().split(" ").map { it.toInt() }
         repeat(c) { col ->
             map[row][col] = input[col]
             if (map[row][col] == 1) cheeseCnt++
         }
    }

    fun bfsForAirChecking() {
        val visited = Array(MAX) { BooleanArray(MAX) { false } }

        val queue: Queue<Pair<Int, Int>> = LinkedList()
        queue.add(Pair(0, 0))
        while (queue.isNotEmpty()) {
            val (currY, currX) = queue.poll()

            repeat(4) {
                val ny = currY + dy[it]
                val nx = currX + dx[it]
                if (ny < 0 || ny >= r || nx < 0 || nx >= c || visited[ny][nx]) return@repeat

                if (map[ny][nx] == 0) {
                    visited[ny][nx] = true
                    queue.add(Pair(ny, nx))
                } else if (map[ny][nx] == 1) {
                    visited[ny][nx] = true
                    map[ny][nx] = 0
                }
            }
        }
    }


    while (cheeseCnt > 0) {
        bfsForAirChecking()
        prevCheeseCnt = cheeseCnt
        cheeseCnt = 0
        repeat(r) { row ->
            repeat(c) { col ->
                if (map[row][col] == 1) cheeseCnt++
            }
        }
        totalHour++
    }

    bw.write("$totalHour\n$prevCheeseCnt")
    bw.flush()
    bw.close()
}
