import java.io.BufferedReader
import java.io.BufferedWriter
import java.io.InputStreamReader
import java.io.OutputStreamWriter

/**
 * DP
 * */

private const val MAX = 1000
val dp = IntArray(MAX + 1)
val arr = IntArray(MAX + 1)

fun main() = with(BufferedReader(InputStreamReader(System.`in`))) {
    val bw = BufferedWriter(OutputStreamWriter(System.out))
    val t = readLine().toInt()
    for (case in 0 until t) {
        val n = readLine().toInt()
        val nums = readLine().split(" ")
        for (idx in 0 until n) {
            arr[idx] = nums[idx].toInt()
            dp[idx] = arr[idx]
        }
        val maxSum = findMaxSubArraySum(n)
        bw.write("" + maxSum + "\n")
    }
    bw.flush()
    bw.close()
}

fun findMaxSubArraySum(n: Int): Int {
    for (idx in 1 until n) {
        if (dp[idx - 1] > 0) dp[idx] = dp[idx - 1] + dp[idx]
    }
    return dp.maxOrNull()!!
}
