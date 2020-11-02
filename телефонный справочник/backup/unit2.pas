unit Unit2;

{$mode objfpc}{$H+}

interface

uses
  Classes, SysUtils, Forms, Controls, Graphics, Dialogs, StdCtrls, Spin;

type

  { TForm2 }

  TForm2 = class(TForm)
    Button1: TButton;
    Button2: TButton;
    ComboBox1: TComboBox;
    Edit1: TEdit;
    Label1: TLabel;
    Label2: TLabel;
    Label3: TLabel;
    SpinEdit1: TSpinEdit;
    procedure Button1Click(Sender: TObject);
    procedure Button2Click(Sender: TObject);
    procedure Label1Click(Sender: TObject);
  private

  public

  end;

var
  Form2: TForm2;

implementation
   uses Unit1;//
{$R *.lfm}

{ TForm2 }

procedure TForm2.Label1Click(Sender: TObject);
begin

end;

procedure TForm2.Button1Click(Sender: TObject);
begin
  Close;

end;

procedure TForm2.Button2Click(Sender: TObject);
begin
  Form1.StringGrid1.RowCount := Form1.StringGrid1.RowCount +1;//добавление новой строки
  Form1.StringGrid1.Cells[0,Form1.StringGrid1.RowCount-1] := Edit1.Text;//имя в 0 столбик
  Form1.StringGrid1.Cells[1,Form1.StringGrid1.RowCount-1] := SpinEdit1.Text;//номер в 1 столбик
  Form1.StringGrid1.Cells[2,Form1.StringGrid1.RowCount-1] := ComboBox1.Text;//тип в 2 столбик
end;

end.

