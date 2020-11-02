unit Unit1;
{
МДК.01.02 "Прикладное программирование"
ЛЗ 36. Разработка программ с графическим интерфейсом
Составитель: Гусятинер Л.Б., 01.05.2020, МГОТУ ККМТ, П1-17, П2-17

Задание.
1. Создать проект "Телефонная книга"

Критерии оценки.
1..5 баллов
}
{$mode objfpc}{$H+}

interface

uses
  Classes, SysUtils, Forms, Controls, Graphics, Dialogs, Unit2, Unit3, Unit4, StdCtrls, Grids;//второй код


type

  { TForm1 }

  TForm1 = class(TForm)
    Button1: TButton;
    Button2: TButton;
    Button3: TButton;
    Button4: TButton;
    Button5: TButton;
    Button6: TButton;
    Button7: TButton;
    OpenDialog1: TOpenDialog;
    SaveDialog1: TSaveDialog;

    StringGrid1: TStringGrid;
    procedure Button1Click(Sender: TObject);
    procedure Button2Click(Sender: TObject);
    procedure Button3Click(Sender: TObject);
    procedure Button4Click(Sender: TObject);
    procedure Button5Click(Sender: TObject);
    procedure Button6Click(Sender: TObject);
    procedure Button7Click(Sender: TObject);

  private

  public

  end;

var
  Form1: TForm1;

implementation

{$R *.lfm}

{ TForm1 }



procedure TForm1.Button1Click(Sender: TObject);
begin
     Form2.Show;//показ 2 формы
end;

procedure TForm1.Button2Click(Sender: TObject);
begin
  Form3.Show;
end;

procedure TForm1.Button3Click(Sender: TObject);
begin
  Form4.Show;
end;

procedure TForm1.Button4Click(Sender: TObject);
begin
  StringGrid1.SortColRow(true,0);//Сортировка
end;

procedure TForm1.Button5Click(Sender: TObject);
begin
  Close;//Закрыть программу
end;

procedure TForm1.Button6Click(Sender: TObject);//Открытие файла txt
var f: text;//
var way: string;//
var arr: array of string;//массив справочника
begin
  OpenDialog1.Execute;//вызов окна открытия
  way := OpenDialog1.Filename;//путь к файлу
  AssignFile(f,way);//подкл. файла к тексту
  reset(f);//подкл. файла к переменной

  StringGrid1.RowCount := StringGrid1.RowCount-(StringGrid1.RowCount-1);//удаление пустых строк

  i := 1;

  while not eof(f) do begin//до конца
        readln(f,way);//чтение
        arr := way.Split([' ']);//разденение пробелом
        StringGrid1.RowCount := StringGrid1.RowCount+1;//добавление новой строки
        StringGrid1.Cells[0,i] := UTF8Encode(arr[0]);//вывод с киррилицей
        StringGrid1.Cells[1,i] := arr[1];
        StringGrid1.Cells[2,i] := arr[2];
        i := i + 1;
  end;



  CloseFile(f);//Закрытие файла
end;

procedure TForm1.Button7Click(Sender: TObject);
var f: text;
var way: string;
var i,g: integer;
begin
  SaveDialog1.Execute;//вызов сохранения
  way := SaveDialog1.FileName;//
  AssignFile(f,way);
  rewrite(f);//открытие для перезаписи

  for i:=1 to StringGrid1.RowCount-1 do begin;
        for g:=0 to StringGrid1.ColCount-1 do begin;
              Write(f,StringGrid1.Cells[g,i] + ' ');//запись значения ячейки с пробелом
        end;
        writeln(f);
  end;
  CloseFile(f);//



end;

end.

