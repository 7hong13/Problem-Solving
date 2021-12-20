import java.io.BufferedReader
import java.io.BufferedWriter
import java.io.InputStreamReader
import java.io.OutputStreamWriter
import java.util.*
import kotlin.math.abs

fun main(args: Array<String>) = with(BufferedReader(InputStreamReader(System.`in`))) {
    val bw = BufferedWriter(OutputStreamWriter(System.out))
    val priorityQueue = PriorityQueue { x1: Int, x2: Int ->
        when {
            abs(x1) != abs(x2) -> abs(x1) - abs(x2)
            else -> x1 - x2
        }
    }

    val n = readLine().toInt()
    repeat(n) {
        when (val x = readLine().toInt()) {
            0 -> bw.write(if (priorityQueue.isEmpty()) "0\n" else priorityQueue.poll().toString() + "\n")
            else -> priorityQueue.add(x)
        }
    }

    bw.flush()
    bw.close()
}
