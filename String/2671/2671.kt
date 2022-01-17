import java.io.BufferedReader
import java.io.BufferedWriter
import java.io.InputStreamReader
import java.io.OutputStreamWriter

fun main(args: Array<String>) = with(BufferedReader(InputStreamReader(System.`in`))) {
    val bw = BufferedWriter(OutputStreamWriter(System.out))
    val input = readLine()

    fun isSubmarine(input: String): Boolean {
        val regex = "(100+1+|01)+".toRegex()
        return input.matches(regex)
    }
    bw.write("" + if (isSubmarine(input)) "SUBMARINE" else "NOISE")

    bw.flush()
    bw.close()
}
