import java.io.BufferedReader
import java.io.BufferedWriter
import java.io.InputStreamReader
import java.io.OutputStreamWriter
import java.lang.Integer.min

/**
 * DP
 * */

private const val MAX = 100000
private val dp = IntArray(MAX + 1) { 999999999 }

fun main(args: Array<String>) = with(BufferedReader(InputStreamReader(System.`in`))) {
    val bw = BufferedWriter(OutputStreamWriter(System.out))
    val n = readLine().toInt()
    val ans = countMinSquareNums(n)

    bw.write(ans.toString())
    bw.flush()

    bw.close()
}

fun countMinSquareNums(n: Int): Int {
    var idx = 1
    while (idx * idx <= n) {
        dp[idx * idx] = 1
        idx++
    }
    if (dp[n] == 1) return dp[n]

    for (idx in 2..n) {
        if (dp[idx] == 1) continue

        var num = 1
        while (num * num < idx) {
            val squareNum = num * num
            dp[idx] = min(dp[squareNum] + dp[idx - squareNum], dp[idx])
            num++
        }
    }

    return dp[n]
}
