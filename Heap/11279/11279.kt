import java.util.*

val pq = PriorityQueue<Int>(Collections.reverseOrder())
fun main(args: Array<String>) {
    val x = readLine()!!.toInt()
    printMaxHeap(x)
}

fun printMaxHeap(n: Int) {
    for (idx in 0 until n) {
        when (val x = readLine()!!.toInt()) {
            0 -> {
                if (pq.isEmpty()) {
                    println("0")
                } else {
                    println(pq.peek())
                    pq.remove()
                }
            }
            else -> pq.add(x)
        }
    }
}
