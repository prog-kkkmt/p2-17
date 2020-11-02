unit Unit4;

{$mode objfpc}{$H+}

interface

uses
  Classes, SysUtils, Forms, Controls, Graphics, Dialogs, StdCtrls;

type

  { TForm4 }

  TForm4 = class(TForm)
    Button1: TButton;
    Button2: TButton;
    Button3: TButton;
    Edit1: TEdit;
    Label1: TLabel;
    procedure Button1Click(Sender: TObject);
    procedure Button2Click(Sender: TObject);
    procedure Button3Click(Sender: TObject);
  private

  public

  end;

var
  Form4: TForm4;
  i: integer;
implementation
uses Unit1;
{$R *.lfm}

{ TForm4 }

procedure TForm4.Button1Click(Sender: TObject);
var res: string;
begin
  res := edit1.Text;
  for i := 0 to Form1.StringGrid1.RowCount-1 do begin
    if (res = Form1.StringGrid1.Cells[0,i]) then begin//если найдено по имени
      Label1.Caption := 'найдено';
      break;
      end
    else
      Label1.Caption := 'не найдено';
    end;

end;

procedure TForm4.Button2Click(Sender: TObject);
begin
  Form1.StringGrid1.DeleteRow(i);//удалить строку
end;

procedure TForm4.Button3Click(Sender: TObject);
begin
  Close;
end;

end.

