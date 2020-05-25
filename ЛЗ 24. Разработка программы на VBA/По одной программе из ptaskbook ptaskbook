Option Explicit

Sub Begin1()
Rem Дана сторона квадрата a. Найти его пкриметр P = 4 * a.
    Dim a As Integer, p As Integer
    a = InputBox("")
    
    p = 4 * a
    MsgBox (p)
End Sub

Sub Integer1()
Rem Дано L в сантиметрах, найти кол-во метров
    Dim l As Integer
    l = InputBox("Введите количество сантиметров")
    MsgBox (l \ 100)
End Sub

Sub Boolean1()
Rem Проверить, является ли число положительным
    Dim a As Integer
    a = InputBox("Введите число")
    MsgBox (a > 0)
End Sub

Sub If1()
Rem Если исло положительное - вычесть из него 8, иначе вывести число не изменяя
    Dim a As Integer
    a = InputBox("Введите число")
    If a > 0 Then
        MsgBox (a + 8)
    Else
        MsgBox (a)
    End If
End Sub

Sub Case1()
Rem Вывести день недели по номеру
    Dim a As Integer
    a = InputBox("Введите число")
    Select Case a
        Case 1
            MsgBox ("Понедельник")
        Case 2
            MsgBox ("Вторник")
        Case 3
            MsgBox ("Среда")
        Case 4
            MsgBox ("Четверг")
        Case 5
            MsgBox ("Пятница")
        Case 6
            MsgBox ("Суббота")
        Case 7
            MsgBox ("Воскресенье")
        Case Else
            MsgBox ("Нету таких дней недели")
    End Select
End Sub

Sub For1()
    Dim k As Integer, n As Integer, i As Integer
    k = InputBox("")
    n = InputBox("")
    
    For i = k To n
        MsgBox (i)
    Next i
End Sub

Sub While5()
    Dim k As Integer, sch As Integer
    k = InputBox("")
    sch = 0
    
    Do While k > 0
        k = k \ 2
        sch = sch + 1
    Loop
    MsgBox (sch)
End Sub

Sub Series5()
    Dim k As Integer, sch As Integer, sum As Integer
    sch = 0
    sum = 0
    Do While sch < 10
        k = InputBox("Введите " & sch + 1 & " число")
        sch = sch + 1
        sum = sum + k
    Loop
    MsgBox (sum)
End Sub

Function swap(ByRef a As Integer, ByRef b As Integer)
    Dim tmp As Integer
    tmp = a
    a = b
    b = tmp
End Function

Sub Proc10()
    Dim a As Integer, b As Integer
    a = InputBox("Input a")
    b = InputBox("Input b")
    Call swap(a, b)
    MsgBox (a & " " & b)
End Sub

Sub Minmax6()
Rem Дано целое число N и набор из N целых чисел. Найти номера первого минимального и последнего максимального элемента из данного набора и вывести их в указанном порядке
    Dim n As Integer, max As Integer, min As Integer, mass(0 To 100) As Integer, i As Integer
    n = InputBox("Input n")
    For i = 0 To n
        mass(i) = InputBox("")
    Next i
    min = mass(0)
    max = mass(0)
    
    For i = 0 To n
        If mass(i) >= max Then
            max = i
        End If
        If mass(i) < min Then
            min = i
        End If
    Next i
    
    MsgBox (min & max)
End Sub

Sub Array7()
Rem Дан массив размера N. Вывести его элементы в обратном порядке.
Dim n As Integer, mass(0 To 100) As Integer, answ As String, i As Integer
n = InputBox("Input n")
For i = 0 To n
    mass(i) = InputBox("")
Next i

For i = n To 1 Step -1
    answ = answ & mass(i) & " "
Next i

MsgBox (answ)
End Sub

Sub Matrix7()
Rem Дана матрица размера M * N и целое число K (1 <= K <= M). Вывести элементы K-й строки данной матрицы.
Const m As Integer = 5, n As Integer = 5
Dim a(1 To m, 1 To n) As Integer, v(1 To n) As Integer, i As Integer, j As Integer, k As Integer, answ As String
 
For i = 1 To m
    For j = 1 To n
        a(i, j) = InputBox("Строка " & i)
    Next j
Next i

k = InputBox("Введите номер строки (номер <= 5)")

For i = 1 To m
    answ = answ & a(k, i) & " "
Next i
MsgBox (answ)
End Sub

Sub String11()
Rem Дана непустая строка S. Вывести строку, содержащую символы строки S, между которыми вставлено по одному пробелу.
    Dim s1 As String, s2 As String, i As Integer
    s1 = InputBox("")
    s2 = ""
    For i = 1 To Len(s1)
        s2 = s2 & Mid(s1, i, 1) & " "
    Next i
    MsgBox (s2)
End Sub

Function MinElem(ByRef mass() As Integer, ByVal n As Integer)
    Dim i As Integer, min As Integer
    min = mass(1)
    For i = 1 To n
        If mass(i) < min Then
            min = i
        End If
    Next i
    MinElem = min
End Function

Function Input_m(ByRef mass() As Integer)
    Dim i As Integer, n As Integer
    n = InputBox("Input n")
    For i = 1 To n
        mass(i) = InputBox(i & " ")
    Next i
    Input_m = n
End Function

Sub Param1()
    Const n As Integer = 100
    Dim a(1 To n) As Integer, b(1 To n) As Integer, c(1 To n) As Integer
    MsgBox (MinElem(a, Input_m(a)) & " " & MinElem(a, Input_m(a)) & " " & MinElem(a, Input_m(a)))
End Sub

Function Fact(ByVal n As Integer) As Integer
    If n = 0 Then
        Fact = 1
    Else
        Fact = Fact(n - 1) * n
    End If
End Function

Sub Recur1()
    Dim n As Integer
    n = InputBox("Input n")
    MsgBox (Fact(n))
End Sub
