import java.io.BufferedReader
import java.io.BufferedWriter
import java.io.InputStreamReader
import java.io.OutputStreamWriter

/**
 * DP
 **/

private const val MAX = 100
private val dp = LongArray(MAX + 1) { -1 }

fun main(args: Array<String>) = with(BufferedReader(InputStreamReader(System.`in`))) {
    val bw = BufferedWriter(OutputStreamWriter(System.out))
    val t = readLine().toInt()

    repeat(t) {
        val n = readLine().toInt()
        bw.write(doPadovanSeq(n).toString() + "\n")
    }

    bw.flush()
    bw.close()
}

fun doPadovanSeq(n: Int): Long {
    if (n in listOf(1, 2, 3)) return 1
    if (dp[n] != -1L) return dp[n]

    dp[n] = doPadovanSeq(n - 3) + doPadovanSeq(n - 2)
    return dp[n]
}
