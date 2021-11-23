import java.io.BufferedReader
import java.io.BufferedWriter
import java.io.InputStreamReader
import java.io.OutputStreamWriter

fun main(args: Array<String>) = with(BufferedReader(InputStreamReader(System.`in`))) {
    val bw = BufferedWriter(OutputStreamWriter(System.out))
    val t = readLine().toInt()
    repeat(t) {
        val numbers = arrayListOf<String>()
        val n = readLine().toInt()
        repeat(n) {
            numbers.add(readLine())
        }
        if (isConsistent(numbers.apply { sort() })) bw.write("YES\n") else bw.write("NO\n")
    }

    bw.flush()
    bw.close()
}

private fun isConsistent(numbers: ArrayList<String>): Boolean {
    for (idx in 0..numbers.size - 2) {
        val currNum = numbers[idx]
        val nextNum = numbers[idx + 1]
        if (nextNum.startsWith(currNum)) return false
    }
    return true
}
