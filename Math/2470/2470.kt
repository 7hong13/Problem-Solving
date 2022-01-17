import java.io.BufferedReader
import java.io.BufferedWriter
import java.io.InputStreamReader
import java.io.OutputStreamWriter
import kotlin.math.abs

private val values = arrayListOf<Int>()

fun main(args: Array<String>) = with(BufferedReader(InputStreamReader(System.`in`))) {
    val n = readLine().toInt()
    readLine().split(" ").forEach { values.add(it.toInt()) }
    printZeroClosestValues(n)
}

private fun printZeroClosestValues(n: Int) {
    val bw = BufferedWriter(OutputStreamWriter(System.out))
    values.sortBy { abs(it) }

    var solution1 = values[0]
    var solution2 = values[1]
    for (idx in 1..n - 2) {
        if (abs(values[idx] + values[idx + 1]) < abs(solution1 + solution2)) {
            solution1 = values[idx]
            solution2 = values[idx + 1]
        }
    }
    if (solution1 < solution2) bw.write("$solution1 $solution2") else bw.write("$solution2 $solution1")

    bw.flush()
    bw.close()
}
