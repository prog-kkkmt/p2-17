unit Unit1;
//калькулятор Калашников
{$mode objfpc}{$H+}

interface

uses
  Classes, SysUtils, Forms, Controls, Graphics, Dialogs, StdCtrls;

type

  { TForm1 }

  TForm1 = class(TForm)
    Button1: TButton;
    Button2: TButton;
    Button3: TButton;
    Button4: TButton;
    Edit1: TEdit;
    Edit2: TEdit;
    Label1: TLabel;
    Label2: TLabel;
    Label3: TLabel;
    Label4: TLabel;
    procedure Button1Click(Sender: TObject);
    procedure Button2Click(Sender: TObject);
    procedure Button3Click(Sender: TObject);
    procedure Button4Click(Sender: TObject);
  private

  public

  end;

var
  Form1: TForm1;

implementation

{$R *.lfm}

{ TForm1 }

procedure TForm1.Button1Click(Sender: TObject);//сложение
var a, b, result:real;
begin
     a := StrToFloat(edit1.Text);
     b := StrToFloat(edit2.Text);
     result := a+b;
     Label4.Caption := FloatToStr(result);
end;

procedure TForm1.Button2Click(Sender: TObject);//умножение
var a, b, result:real;
begin
     a := StrToFloat(edit1.Text);
     b := StrToFloat(edit2.Text);
     result := a*b;
     Label4.Caption := FloatToStr(result);
end;

procedure TForm1.Button3Click(Sender: TObject);//вычитание
var a, b, result:real;
begin
     a := StrToFloat(edit1.Text);
     b := StrToFloat(edit2.Text);
     result := a-b;
     Label4.Caption := FloatToStr(result);
end;

procedure TForm1.Button4Click(Sender: TObject);//деление
var a,b,result:real;
begin
     a := StrToFloat(edit1.Text);
     b := StrToFloat(edit2.Text);
     if (b <> 0) then begin //если b не равно 0
     result := a / b;
     Label4.Caption := FloatToStr(result);
     end
     else//если b = 0
       Label4.Caption := 'Делить на ноль нельзя';
end;

end.

