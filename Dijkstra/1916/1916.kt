import java.io.BufferedReader
import java.io.BufferedWriter
import java.io.InputStreamReader
import java.io.OutputStreamWriter
import java.util.*

private const val MAX = 1000
private const val INF = 999999999
fun main(args: Array<String>) = with(BufferedReader(InputStreamReader(System.`in`))) {
    val bw = BufferedWriter(OutputStreamWriter(System.out))
    val n = readLine().toInt()
    val m = readLine().toInt()
    val graph = Array(MAX + 1) { arrayListOf<Pair<Int, Int>>() } // destination, cost
    val dist = IntArray(MAX + 1) { INF }
    val pq =  PriorityQueue(Comparator<Pair<Int, Int>> { x1, x2 ->
        when (x1.first) {
            x2.first -> x1.second - x2.second
            else -> x1.first - x2.first
        }
    }) // cost, destination

    repeat(m) {
        val (u, v, w) = readLine().split(" ").map { it.toInt() }
        graph[u].add(Pair(v, w))
    }
    val (start, dest) = readLine().split(" ").map { it.toInt() }

    fun dijkstra() {
        pq.add(Pair(0, start))
        dist[start] = 0
        while (pq.isNotEmpty()) {
            val (minCost, u) = pq.poll()
            if (dist[u] < minCost) continue
            for (v in graph[u]) {
                if (dist[u] + v.second >= dist[v.first]) continue
                dist[v.first] = dist[u] + v.second
                pq.add(Pair(dist[v.first], v.first))
            }
        }
    }

    dijkstra()
    bw.write("${dist[dest]}")

    bw.flush()
    bw.close()
}
