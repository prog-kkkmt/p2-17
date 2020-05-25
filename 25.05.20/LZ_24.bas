Option Explicit

Sub Begin()
Rem Äàíà ñòîðîíà êâàäðàòà a. Íàéòè åãî ïåðèìåòð P = 4·a.
Dim p As Double, a As Double
a = InputBox("")
p = 4 * a
MsgBox (p)
End Sub

Sub Integer1()
Rem Äàíî ðàññòîÿíèå L â ñàíòèìåòðàõ. Èñïîëüçóÿ îïåðàöèþ äåëåíèÿ íàöåëî, íàéòè êîëè÷åñòâî ïîëíûõ ìåòðîâ â íåì (1 ìåòð = 100 ñì).
Dim L As Integer, M As Integer
M = 100
L = InputBox("")
MsgBox (L \ M)
End Sub

Sub Bool()
Rem Äàíî öåëîå ÷èñëî A. Ïðîâåðèòü èñòèííîñòü âûñêàçûâàíèÿ: «×èñëî A ÿâëÿåòñÿ ïîëîæèòåëüíûì».
Dim a As Double
a = InputBox("")
MsgBox (a > 0)
End Sub

Sub if1()
Rem Äàíî öåëîå ÷èñëî. Åñëè îíî ÿâëÿåòñÿ ïîëîæèòåëüíûì, òî âû÷åñòü èç íåãî 8; â ïðîòèâíîì ñëó÷àå íå èçìåíÿòü åãî. Âûâåñòè ïîëó÷åííîå ÷èñëî.
Dim a As Integer
a = InputBox("")
If a > 0 Then
    a = a - 8
End If

MsgBox (a)
End Sub

Sub Case1()
Rem Äàíî öåëîå ÷èñëî â äèàïàçîíå 1–7. Âûâåñòè ñòðîêó — íàçâàíèå äíÿ íåäåëè, ñîîòâåòñòâóþùåå äàííîìó ÷èñëó (1 — «ïîíåäåëüíèê», 2 — «âòîðíèê» è ò. ä.).
Dim x As Integer
    x = InputBox("")
    Select Case x
        Case 1
            MsgBox ("Ïîíåäåëüíèê")
        Case 2
            MsgBox ("Âòîðíèê")
        Case 3
            MsgBox ("Ñðåäà")
        Case 4
            MsgBox ("×åòâåðã")
        Case 5
            MsgBox ("Ïÿòíèöà")
        Case 6
            MsgBox ("Ñóááîòà")
        Case 7
            MsgBox ("Âîñêðåñåíüå")
        Case Else
            MsgBox ("íåèçâåñòíîå")
    End Select
End Sub

Sub For1()
Rem Äàíû öåëûå ÷èñëà K è N (N > 0). Âûâåñòè N ðàç ÷èñëî K.
Dim K As Integer, n As Integer, i As Integer
K = InputBox("")
n = InputBox("")
For i = 0 To n
    MsgBox (K & " ")
Next i
End Sub


Sub While1()
Rem Äàíû ïîëîæèòåëüíûå ÷èñëà A è B (A > B). Íà îòðåçêå äëèíû A ðàçìåùåíî ìàêñèìàëüíî âîçìîæíîå êîëè÷åñòâî îòðåçêîâ äëèíû B (áåç íàëîæåíèé). Íå èñïîëüçóÿ îïåðàöèè óìíîæåíèÿ è äåëåíèÿ, íàéòè äëèíó íåçàíÿòîé ÷àñòè îòðåçêà A.
Dim a As Integer, b As Integer
    a = InputBox("")
    b = InputBox("")
    Do While a >= b
        a = a - b
    Loop
    MsgBox (a)
End Sub

Sub Series1()
Rem Äàíû äåñÿòü âåùåñòâåííûõ ÷èñåë. Íàéòè èõ ñóììó.
Dim i As Integer, sum As Double, p As Double

For i = 1 To 10
    p = InputBox("")
    sum = sum + p
Next i
    MsgBox (sum)
End Sub
Sub ProcProc(a As Double, ByRef b As Double)
b = a * a * a
End Sub

Sub Proc1()
Rem Îïèñàòü ïðîöåäóðó PowerA3(A, B), âû÷èñëÿþùóþ òðåòüþ ñòåïåíü ÷èñëà A è âîçâðàùàþùóþ åå â ïåðåìåííîé B (A — âõîäíîé, B — âûõîäíîé ïàðàìåòð; îáà ïàðàìåòðà ÿâëÿþòñÿ âåùåñòâåííûìè). Ñ ïîìîùüþ ýòîé ïðîöåäóðû íàéòè òðåòüè ñòåïåíè ïÿòè äàííûõ ÷èñåë.
Dim i As Integer, a As Double, b As Double
b = 0
For i = 1 To 5
    a = InputBox("")
    Call ProcProc(a, b)
    
    MsgBox (a & " " & b)
Next i
End Sub

Sub MinMax()
Rem Äàíî öåëîå ÷èñëî N è íàáîð èç N öåëûõ ÷èñåë. Íàéòè íîìåðà ïåðâîãî ìèíèìàëüíîãî è ïîñëåäíåãî ìàêñèìàëüíîãî ýëåìåíòà èç äàííîãî íàáîðà è âûâåñòè èõ â óêàçàííîì ïîðÿäêå
    Dim n As Integer, max As Integer, min As Integer, mass(0 To 100) As Integer, i As Integer
    n = InputBox("Input n")
    For i = 1 To n
        mass(i) = InputBox("")
    Next i
    min = mass(0)
    max = mass(0)
    
    For i = 1 To n
        If mass(i) >= max Then
            max = mass(i)
        End If
        If mass(i) < min Then
            min = mass(i)
        End If
    Next i
    
    MsgBox (min & " " & max)
End Sub

Sub Array1()
Dim n As Integer, i As Integer, mas(0 To 100) As Integer
mas(0) = 1
n = InputBox("")
For i = 1 To n
    mas(i) = mas(i - 1) + 2
Next i

For i = 0 To n
    MsgBox (mas(i) & " ")
Next i
End Sub

Sub Matrix1()
Dim mas(0 To 100, 0 To 100) As Integer, M As Integer, n As Integer, i As Integer, j As Integer
M = InputBox("")
n = InputBox("")
For i = 1 To M
    For j = 1 To n
        mas(i, j) = 10 * i
        MsgBox (mas(i, j))
    Next j
Next i
        
End Sub

Sub String1()
Dim a As String
a = InputBox("")
MsgBox (Asc(a))
End Sub

Sub MinEl(n As Integer)
Dim min As Integer, i As Integer, mas(0 To 100) As Integer
    For i = 1 To n
        mas(i) = InputBox("")
    Next i
    
    min = mas(1)
    
    For i = 1 To n
        If mas(i) < min Then
            min = mas(i)
        End If
    Next i
    
    MsgBox (min)
End Sub

Sub param1()
Dim n As Integer
n = InputBox("")
MinEl (n)
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
