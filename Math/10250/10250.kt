import java.util.*

fun main(args: Array<String>) = with(Scanner(System.`in`)) {
    for (it in 1..nextInt()) {
        val h = nextInt()
        val w = nextInt()
        val n = nextInt()

        val y = (n - 1) % h + 1
        val x = (n - 1) / h + 1
        println(y * 100 + x)
    }
}
