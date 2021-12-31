import java.io.BufferedReader
import java.io.BufferedWriter
import java.io.InputStreamReader
import java.io.OutputStreamWriter
import kotlin.math.abs
import kotlin.math.min

private const val INF = 999999999
fun main(args: Array<String>) = with(BufferedReader(InputStreamReader(System.`in`))) {
    val bw = BufferedWriter(OutputStreamWriter(System.out))
    val points = arrayListOf<Pair<Int, Int>>()

    fun calDist(u: Pair<Int, Int>, v: Pair<Int, Int>): Int {
        return abs(u.first - v.first) + abs(u.second - v.second)
    }

    fun floyd(n: Int) {
        val dp = Array(n + 2) { IntArray(n + 2) { INF } }

        repeat(n + 2) { u ->
            repeat(n + 2) { v ->
                if (u == v) return@repeat
                val dist = calDist(points[u], points[v])
                if (dist <= 1000) dp[u][v] = 1
            }
        }

        repeat(n + 2) { k ->
            repeat(n + 2) { u ->
                repeat(n + 2) { v ->
                    dp[u][v] = min(dp[u][v], dp[u][k] + dp[k][v])
                }
            }
        }

        bw.write(if (dp[0][n + 1] == INF) "sad\n" else "happy\n")
    }

    val t = readLine().toInt()
    repeat(t) {
        points.clear()

        val n = readLine().toInt()
        var point = readLine().split(" ").map { it.toInt() }
        points.add(Pair(point[0], point[1])) // 집

        repeat(n) { //편의점
            point = readLine().split(" ").map { it.toInt() }
            points.add(Pair(point[0], point[1]))
        }

        point = readLine().split(" ").map { it.toInt() }
        points.add(Pair(point[0], point[1])) // 도착지

        floyd(n)
    }

    bw.flush()
    bw.close()
}
