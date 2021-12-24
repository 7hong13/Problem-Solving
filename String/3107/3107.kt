import java.io.BufferedReader
import java.io.BufferedWriter
import java.io.InputStreamReader
import java.io.OutputStreamWriter

fun main(args: Array<String>) = with(BufferedReader(InputStreamReader(System.`in`))) {
    val bw = BufferedWriter(OutputStreamWriter(System.out))
    val shortIpv6 = readLine()

    fun restoreOriginalIpv6(): String {
        val chunks = shortIpv6.split("::")
        val frontChunks = chunks[0].split(":")
        var result = ""
        for (chunk in frontChunks) {
            repeat (4 - chunk.length) { result += "0" }
            result += "$chunk:"
        }

        if (chunks.size == 2) {
            val backChunks = chunks[1].split(":")
            repeat(8 - frontChunks.size - backChunks.size) { result += "0000:" }
            for (chunk in backChunks) {
                repeat (4 - chunk.length) { result += "0" }
                result += "$chunk:"
            }
        }

        return result.dropLast(1)
    }

    val originalIpv6 = restoreOriginalIpv6()
    bw.write(originalIpv6)
    bw.flush()
    bw.close()
}
