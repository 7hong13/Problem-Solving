import java.io.BufferedReader
import java.io.BufferedWriter
import java.io.InputStreamReader
import java.io.OutputStreamWriter

fun main(args: Array<String>) = with(BufferedReader(InputStreamReader(System.`in`))) {
    val bw = BufferedWriter(OutputStreamWriter(System.out))
    val m = readLine().toInt()
    var set = 0

    repeat(m) {
        val input = readLine().split(" ")
        val command = input[0]
        val number = if (input.size == 2) input[1].toInt() else 0
        when {
            command.startsWith("add") -> set = set or (1 shl number)
            command.startsWith("remove") -> set = set and (1 shl number).inv()
            command.startsWith("check") -> bw.write(if (set and (1 shl number) == 0) "0\n" else "1\n")
            command.startsWith("toggle") -> set = set xor (1 shl number)
            command.startsWith("all") -> set = (1 shl 21) - 1
            command.startsWith("empty") -> set = 0
        }
        println(set.toString(2))
    }

    bw.flush()
    bw.close()
}
