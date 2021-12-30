import java.io.BufferedReader
import java.io.BufferedWriter
import java.io.InputStreamReader
import java.io.OutputStreamWriter

private const val MAX = 200
fun main(args: Array<String>) = with(BufferedReader(InputStreamReader(System.`in`))) {
    val bw = BufferedWriter(OutputStreamWriter(System.out))
    val parentOf = IntArray(MAX + 1) { -1 }
    val n = readLine().toInt()
    val m = readLine().toInt()

    fun find(u: Int): Int {
        if (parentOf[u] == -1) return u
        return find(parentOf[u])
    }

    fun merge(u: Int, v: Int) {
        val uParent = find(u)
        val vParent = find(v)
        if (uParent != vParent) parentOf[vParent] = uParent
    }

    repeat(n) { row ->
        val input = readLine().split(" ").map { it.toInt() }
        repeat(n) { col ->
            if (input[col] == 1) merge(row + 1, col + 1)
        }
    }

    val dest = readLine().split(" ").map { it.toInt() }
    var isConnected = true
    for (idx in 0 until m - 1) {
        if (find(dest[idx]) != find(dest[idx + 1])) {
            isConnected = false
            break
        }
    }

    bw.write(if (isConnected) "YES" else "NO")
    bw.flush()
    bw.close()
}
