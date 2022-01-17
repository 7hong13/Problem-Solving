import java.io.BufferedReader
import java.io.BufferedWriter
import java.io.InputStreamReader
import java.io.OutputStreamWriter

/**
 * DFS
 * */

private const val MAX = 1000
private val visited = BooleanArray(MAX + 1) { false }
private val adjList = Array(MAX + 1) { mutableListOf<Int>() }

fun main(args: Array<String>) = with(BufferedReader(InputStreamReader(System.`in`))) {
    val bw = BufferedWriter(OutputStreamWriter(System.out))
    val (n, m) = readLine().split(" ").map { it.toInt() }
    repeat(m) {
        val (u, v) = readLine().split(" ").map { it.toInt() }
        adjList[u].add(v)
        adjList[v].add(u)
    }

    var cnt = 0

    for (idx in 1..n) {
        if (!visited[idx]) {
            visited[idx] = true
            dfs(idx)
            cnt++
        }
    }

    bw.write(cnt.toString())
    bw.flush()

    bw.close()
}

fun dfs(start: Int) {
    for (idx in 0 until adjList[start].size) {
        val u = adjList[start][idx]
        if (!visited[u]) {
            visited[u] = true
            dfs(u)
        }
    }
}
