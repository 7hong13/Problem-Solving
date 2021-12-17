import java.io.BufferedReader
import java.io.BufferedWriter
import java.io.InputStreamReader
import java.io.OutputStreamWriter

private val pocketMonsByNumber = arrayListOf<String>()
private val pocketMonsByName = hashMapOf<String, Int>()

fun main(args: Array<String>) = with(BufferedReader(InputStreamReader(System.`in`))) {
    val bw = BufferedWriter(OutputStreamWriter(System.out))
    val (n, m) = readLine().split(" ").map { it.toInt() }
    // pocketMons information input
    repeat(n) {
        val name = readLine()
        pocketMonsByNumber.add(name)
        pocketMonsByName[name] = it + 1
    }

    // questions
    repeat(m) {
        val input = readLine()

        if (input.first().isDigit()) {
            bw.write("" + pocketMonsByNumber[input.toInt() - 1] + "\n")
        } else {
            bw.write("" + pocketMonsByName[input] + "\n")
        }
    }

    bw.flush()
    bw.close()
}
