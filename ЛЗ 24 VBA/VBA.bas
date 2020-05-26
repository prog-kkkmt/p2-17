Public Sub Begin1()
Dim a As Integer, p As Integer
a = InputBox("")
p = a * 4
MsgBox p
End Sub

Public Sub Integer1()
Dim a As Integer, L As Integer
L = InputBox("")
a = L \ 100
MsgBox a
End Sub

Public Sub Boolean1()
Dim a As Integer, b As Boolean
a = InputBox("")
b = False
If a > -1 Then
    b = True
End If
MsgBox b
End Sub

Public Sub If1()
Dim a As Integer
a = InputBox("")
If a > -1 Then
    a = a - 8
End If
MsgBox a
End Sub


Public Sub Case1()
Dim a As Integer
a = InputBox("")
Select Case a
    Case 1
        MsgBox "Ïîíåäåëüíèê"
    Case 2
        MsgBox "Âòîðíèê"
    Case 3
        MsgBox "Ñðåäà"
    Case 4
        MsgBox "×åòâåðã"
    Case 5
        MsgBox "Ïÿòíèöà"
    Case 6
        MsgBox "Ñóááîòà"
    Case 7
        MsgBox "Âîñêðåñåíüå"
End Select
End Sub


Public Sub For1()
Dim k As Integer, n As Integer
k = InputBox("")
n = InputBox("")
For i = 1 To n Step 1
    MsgBox k
Next
End Sub

Public Sub While1()
Dim a As Integer, b As Integer, i As Integer
i = 0
a = InputBox("")
b = InputBox("")
Do While a >= b
   i = i + 1
   a = a - b
Loop
MsgBox a
End Sub

Public Sub Series1()
Dim n As Double, i As Integer, sum As Double
For i = 1 To 10 Step 1
    n = InputBox("")
    sum = sum + n
Next
MsgBox sum
End Sub

Function swap(ByRef a As Integer, ByRef b As Integer)
    Dim buf As Integer
    buf = a
    a = b
    b = buf
End Function

Public Sub Proc10()
Dim a As Integer, b As Integer
a = InputBox("")
b = InputBox("")
Call swap(a, b)
MsgBox (a & " " & b)
End Sub


Public Sub minmax3()
Dim n As Integer, a As Integer, b As Integer, max As Integer, p As Integer
max = 0
n = InputBox("")
For i = 1 To n Step 1
    a = InputBox("a")
    b = InputBox("b")
    p = (a + b) * 2
    
    If p > max Then
        max = p
    End If
Next
MsgBox max
End Sub


Public Sub Array1()
Dim n As Integer, mas(100) As Integer, i As Integer, str As String
n = InputBox("n")
mas(0) = 1
str = str & mas(0) & " "
For i = 1 To n - 1
    mas(i) = mas(i - 1) + 2
    str = str & mas(i) & " "
Next
MsgBox (str)
End Sub


Public Sub Matrix1()
Dim n As Integer, mas(10, 10) As Integer, j As Integer, i As Integer, str As String
n = InputBox("m")
m = InputBox("n")
For i = 0 To m
    For j = 0 To n
        mas(i, j) = (i + 1) * 10
        str = str & mas(i, j) & " "
    Next
    str = str & " | "
Next
MsgBox (str)
End Sub


Public Sub String11()
Dim str As String, str2 As String, i As Integer
str = InputBox("str")
str2 = ""
For i = 1 To Len(str)
    str2 = str2 & Mid(str, i, 1) & " "
Next
MsgBox (str2)
End Sub

Function MinElem(ByRef mas() As Integer, ByRef n As Integer)
    Dim i As Integer, min As Integer
    min = mas(1)
    For i = 2 To n
        If mas(i) < min Then
            min = mas(i)
        End If
    Next
    MinElem = min
End Function


Public Sub param1()
    Dim n As Integer, a(100) As Integer, i As Integer
    n = InputBox("n")
    For i = 1 To n
        a(i) = InputBox("mas[i]")
    Next
    MsgBox (MinElem(a, n))
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
    n = InputBox("n")
    MsgBox (Fact(n))
End Sub
