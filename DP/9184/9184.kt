import java.io.BufferedReader
import java.io.BufferedWriter
import java.io.InputStreamReader
import java.io.OutputStreamWriter

/**
 * DP
 * */

private const val MAX = 20
private val dp = Array(MAX + 1) { Array(MAX + 1) { Array(MAX + 1) { -1 } } }

fun main(args: Array<String>) = with(BufferedReader(InputStreamReader(System.`in`))) {
    val bw = BufferedWriter(OutputStreamWriter(System.out))

    while (true) {
        val (a, b, c) = readLine().split(" ").map { it.toInt() }
        if (a == -1 && b == -1 && c == -1) break

        bw.write("w($a, $b, $c) = ${recursiveW(a, b, c)} \n")
    }

    bw.flush()
    bw.close()
}

private fun recursiveW(a: Int, b: Int, c: Int): Int {
    if (a <= 0 || b <= 0 || c <= 0) return 1
    if (a > 20 || b > 20 || c > 20) return recursiveW(20, 20, 20)
    if (dp[a][b][c] != -1) return dp[a][b][c]

    if (b in (a + 1) until c) {
        dp[a][b][c] = recursiveW(a, b, c - 1) + recursiveW(a, b - 1, c - 1) - recursiveW(a, b - 1, c)
    } else {
        dp[a][b][c] =
            recursiveW(a - 1, b, c) + recursiveW(a - 1, b - 1, c) + recursiveW(a - 1, b, c - 1) - recursiveW(a - 1, b - 1, c - 1)
    }
    return dp[a][b][c]
}
