import java.io.BufferedReader
import java.io.BufferedWriter
import java.io.InputStreamReader
import java.io.OutputStreamWriter

/**
 * Greedy
 * */

fun main(args: Array<String>) = with(BufferedReader(InputStreamReader(System.`in`))) {
    val bw = BufferedWriter(OutputStreamWriter(System.out))
    val input = readLine().split(" ").map { it.toInt() }
    val n = input[0]
    val k = input[1]
    var ans = n
    while (true) {
        if (countMinBottles(ans) <= k) break
        else ans++
    }
    bw.write((ans - n).toString())
    bw.flush()

    bw.close()
}

fun countMinBottles(n: Int): Int {
    var cnt = 0
    var totalBottles = n
    while (totalBottles > 0) {
        if (totalBottles % 2 == 1) cnt++
        totalBottles /= 2
    }
    return cnt
}
