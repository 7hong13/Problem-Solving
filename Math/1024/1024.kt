import java.io.BufferedReader
import java.io.BufferedWriter
import java.io.InputStreamReader
import java.io.OutputStreamWriter

// n = x + (x + 1) + ... + (x + L - 1)
// n = L * x + (L - 1) * L / 2
// x = (n - L * (L - 1) / 2) / L

fun main(args: Array<String>) = with(BufferedReader(InputStreamReader(System.`in`))) {
    val bw = BufferedWriter(OutputStreamWriter(System.out))
    val (n, l) = readLine().split(" ").map { it.toInt() }

    fun findContinuousNumbers(): Pair<Int, Int>? {
        for (len in l..100) {
            val value = n - len * (len - 1) / 2
            val x = value / len
            if (value % len == 0 && x >= 0) return Pair(x, len)
        }
        return null
    }

    val result = findContinuousNumbers()
    if (result == null) {
        bw.write("-1")
    } else {
        repeat(result.second - 1) { bw.write((result.first + it).toString() + " ")}
        bw.write((result.first + result.second - 1).toString())
    }

    bw.flush()
    bw.close()
}
