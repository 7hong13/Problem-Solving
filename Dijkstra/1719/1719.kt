import java.io.BufferedReader
import java.io.BufferedWriter
import java.io.InputStreamReader
import java.io.OutputStreamWriter
import java.util.*

private const val MAX = 200
private const val INF = 999999999
fun main(args: Array<String>) = with(BufferedReader(InputStreamReader(System.`in`))) {
    val bw = BufferedWriter(OutputStreamWriter(System.out))
    val graph = Array(MAX + 1) { arrayListOf<Pair<Int, Int>>() } // destination, cost
    val dist = IntArray(MAX + 1) { INF }
    val trace = IntArray(MAX + 1)
    val pq = PriorityQueue(Comparator<Pair<Int, Int>> { x1, x2 ->
        when (x1.first) {
            x2.first -> x1.second - x2.second
            else -> x1.first - x2.first
        } // cost, destination
    })

    val (n, m) = readLine().split(" ").map { it.toInt() }
    repeat(m) {
        val (u, v, w) = readLine().split(" ").map { it.toInt() }
        graph[u].add(Pair(v, w))
        graph[v].add(Pair(u, w))
    }

    fun dijkstra(start: Int) {
        pq.add(Pair(0, start))
        dist.forEachIndexed { idx, _ -> dist[idx] = INF }
        dist[start] = 0
        while (pq.isNotEmpty()) {
            val (minDist, v) = pq.poll()
            if (dist[v] < minDist) continue

            for (u in graph[v]) {
                if (dist[u.first] <= dist[v] + u.second) continue
                dist[u.first] = dist[v] + u.second
                trace[u.first] = v
                pq.add(Pair(dist[u.first], u.first))
            }
        }
    }

    fun findRoute(start: Int) {
        repeat(n) {
            if (it + 1 == start) bw.write("- ")
            else {
                var idx = it + 1
                while (true) {
                    if (trace[idx] == start) {
                        bw.write("$idx ")
                        break
                    }
                    idx = trace[idx]
                }
            }
        }
        bw.write("\n")
    }

    repeat(n) {
        dijkstra(it + 1)
        findRoute(it + 1)
    }

    bw.flush()
    bw.close()
}
