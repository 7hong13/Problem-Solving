import java.io.BufferedReader
import java.io.BufferedWriter
import java.io.InputStreamReader
import java.io.OutputStreamWriter

private const val MAX = 500
private val ground = Array(MAX + 1) { IntArray(MAX + 1) { 0 } }

fun main(args: Array<String>) = with(BufferedReader(InputStreamReader(System.`in`))) {
    val (n, m, b) = readLine().split(" ").map { it.toInt() }
    repeat(n) { row ->
        ground[row] = readLine().split(" ").map { it.toInt() }.toIntArray()
    }
    printMinTimeAndHeight(n, m, b)
}

fun printMinTimeAndHeight(n: Int, m: Int, b: Int) {
    val bw = BufferedWriter(OutputStreamWriter(System.out))
    var minTime = -1
    var height = 0

    repeat(256 + 1) { h->
        var under = 0
        var upper = 0
        repeat(n) { row ->
            repeat(m) { col ->
                if (ground[row][col] < h) under += h - ground[row][col]
                if (ground[row][col] > h) upper += ground[row][col] - h
            }
        }

        if (b + upper < under) return@repeat

        val time = under + upper * 2
        if (time < minTime || minTime == -1 || (minTime == time && h > height)) {
            minTime = time
            height = h
        }
    }

    bw.write("$minTime $height")
    bw.flush()
    bw.close()
}
