import java.util.*

fun main(args: Array<String>) = with(Scanner(System.`in`)) {
    var a = nextInt()
    var b = nextInt()
    var c = nextInt()

    while (!(a == 0 && b == 0 && c == 0)) {
        val squares = arrayOf(a * a, b * b, c * c)
        squares.sort()
        if (squares[0] + squares[1] == squares[2]) println("right") else println("wrong")

        a = nextInt()
        b = nextInt()
        c = nextInt()
    }
}
