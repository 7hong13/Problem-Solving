import java.io.BufferedReader
import java.io.BufferedWriter
import java.io.InputStreamReader
import java.io.OutputStreamWriter

fun main(args: Array<String>) = with(BufferedReader(InputStreamReader(System.`in`))) {
    val bw = BufferedWriter(OutputStreamWriter(System.out))
    val positives = arrayListOf<Int>()
    val negatives = arrayListOf<Int>()
    var hasZero = false
    val n = readLine().toInt()

    var sum = 0L
    repeat(n) {
        val number = readLine().toInt()
        when {
            number > 0 -> positives.add(number)
            number < 0 -> negatives.add(number)
            number == 0 -> hasZero = true
        }
        sum += number
    }

    positives.sort()
    negatives.sort()

    var boundSum = 0L
    while (positives.size > 1) {
        val num1 = positives.removeLast()
        val num2 = positives.removeLast()
        boundSum += if (num1 == 1 || num2 == 1) num1 + num2 else num1 * num2
    }
    if (positives.isNotEmpty()) boundSum += positives[0]

    while (negatives.size > 1) {
        boundSum += negatives.removeFirst() * negatives.removeFirst()
    }
    if (negatives.isNotEmpty() && !hasZero) boundSum += negatives[0]

    bw.write("" + if (sum > boundSum) sum else boundSum)
    bw.flush()
}
