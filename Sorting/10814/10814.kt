import java.io.BufferedReader
import java.io.BufferedWriter
import java.io.InputStreamReader
import java.io.OutputStreamWriter

private val members = arrayListOf<Pair<Int, String>>()

fun main(args: Array<String>) = with(BufferedReader(InputStreamReader(System.`in`))) {
    val bw = BufferedWriter(OutputStreamWriter(System.out))
    val n = readLine().toInt()
    repeat(n) {
        val input = readLine().split(" ")
        members.add(Pair(input[0].toInt(), input[1]))
    }

    members.sortBy { it.first } // stable sorting

    repeat(n) {
        bw.write("" + members[it].first + " " + members[it].second + "\n")
    }

    bw.flush()
    bw.close()
}
