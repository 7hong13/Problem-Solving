import java.io.BufferedReader
import java.io.BufferedWriter
import java.io.InputStreamReader
import java.io.OutputStreamWriter

private const val MAX = 8
fun main(args: Array<String>) = with(BufferedReader(InputStreamReader(System.`in`))) {
    val bw = BufferedWriter(OutputStreamWriter(System.out))
    val (n, m) = readLine().split(" ").map { it.toInt() }
    val visited = BooleanArray(MAX + 1) { false }

    fun dfs(start: Int, cnt: Int) {
        if (cnt == m) {
            visited.forEachIndexed { idx, value -> if (value) bw.write("$idx ") }
            bw.write("\n")
            return
        }

        for (idx in start..n) {
            visited[idx] = true
            dfs(idx + 1, cnt + 1)
            visited[idx] = false
        }
    }

    dfs(1, 0)

    bw.flush()
    bw.close()
}
