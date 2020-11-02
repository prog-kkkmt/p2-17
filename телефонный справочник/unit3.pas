unit Unit3;

{$mode objfpc}{$H+}

interface

uses
  Classes, SysUtils, Forms, Controls, Graphics, Dialogs, StdCtrls, Spin;

type

  { TForm3 }

  TForm3 = class(TForm)
    Button1: TButton;
    Button2: TButton;
    Button3: TButton;
    ComboBox1: TComboBox;
    Edit1: TEdit;
    Edit2: TEdit;
    Edit3: TEdit;
    Label1: TLabel;
    SpinEdit1: TSpinEdit;
    procedure Button1Click(Sender: TObject);
    procedure Button2Click(Sender: TObject);
    procedure Button3Click(Sender: TObject);
    procedure SpinEdit1Change(Sender: TObject);
  private

  public

  end;

var
  Form3: TForm3;
  i: integer;
implementation
uses Unit1;
{$R *.lfm}

{ TForm3 }

procedure TForm3.Button1Click(Sender: TObject);
var count:string;

begin
  count := edit1.Text;
  for i:= 0 to Form1.StringGrid1.RowCount - 1 do begin
    if (count = Form1.StringGrid1.Cells[0,i]) then begin
      Label1.Caption := 'найдено';
      Break;
      end
    else
        Label1.Caption := 'не найдено';
    end;


end;

procedure TForm3.Button2Click(Sender: TObject);
begin
  {
  изменение значений
  }
  Form1.StringGrid1.Cells[0,i] := edit2.Text;
  Form1.StringGrid1.Cells[1,i] := SpinEdit1.Text;
  Form1.StringGrid1.Cells[2,i] := ComboBox1.Text;
end;

procedure TForm3.Button3Click(Sender: TObject);
begin
  Close;
end;

procedure TForm3.SpinEdit1Change(Sender: TObject);
begin

end;

{ TForm3 }



end.

