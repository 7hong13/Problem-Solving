import java.io.BufferedReader
import java.io.BufferedWriter
import java.io.InputStreamReader
import java.io.OutputStreamWriter

private const val MAX = 1000
fun main(args: Array<String>) = with(BufferedReader(InputStreamReader(System.`in`))) {
    val bw = BufferedWriter(OutputStreamWriter(System.out))
    val parentOf = IntArray(MAX + 1) { -1 }
    val t = readLine().toInt()

    fun find(u: Int): Int {
        if (parentOf[u] == -1) return u
        return find(parentOf[u])
    }

    fun union(u: Int, v: Int) {
        val uParent = find(u)
        val vParent = find(v)
        if (uParent != vParent) parentOf[vParent] = uParent
    }

    fun isTree(nodeCnt: Int, edgeCnt: Int): Boolean {
        if (nodeCnt - 1 != edgeCnt) return false
        val root = find(1)
        for (node in 2..nodeCnt) {
            if (find(node) != root) return false
        }
        return true
    }

    repeat(t) {
        parentOf.forEachIndexed { index, _ -> parentOf[index] = -1 }
        val n = readLine().toInt()
        val m = readLine().toInt()

        repeat(m) {
            val (u, v) = readLine().split(" ").map { it.toInt() }
            union(u, v)
        }

        if (isTree(n, m)) bw.write("tree\n") else bw.write("graph\n")
    }

    bw.flush()
    bw.close()
}
