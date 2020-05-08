object Form2: TForm2
  Left = 0
  Top = 0
  Caption = 'Form2'
  ClientHeight = 473
  ClientWidth = 710
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  OldCreateOrder = False
  OnCreate = FormCreate
  PixelsPerInch = 96
  TextHeight = 13
  object Label1: TLabel
    Left = 8
    Top = 296
    Width = 103
    Height = 13
    Caption = #1050#1086#1083#1080#1095#1077#1089#1090#1074#1086' '#1079#1072#1087#1080#1089#1077#1081
  end
  object Label2: TLabel
    Left = 74
    Top = 5
    Width = 93
    Height = 13
    Caption = #1048#1089#1093#1086#1076#1085#1099#1077' '#1076#1072#1085#1085#1099#1077
  end
  object Label3: TLabel
    Left = 217
    Top = 296
    Width = 78
    Height = 13
    Caption = #1050#1083#1102#1095' '#1101#1083#1077#1084#1077#1085#1090#1072
  end
  object Label4: TLabel
    Left = 357
    Top = 296
    Width = 78
    Height = 13
    Caption = #1050#1083#1102#1095' '#1101#1083#1077#1084#1077#1085#1090#1072
  end
  object StringGrid1: TStringGrid
    Left = 56
    Top = 24
    Width = 129
    Height = 249
    ColCount = 2
    RowCount = 10
    Options = [goFixedVertLine, goFixedHorzLine, goVertLine, goHorzLine, goRangeSelect, goEditing]
    TabOrder = 0
    RowHeights = (
      24
      24
      24
      24
      24
      25
      24
      24
      24
      24)
  end
  object TreeView1: TTreeView
    Left = 280
    Top = 24
    Width = 145
    Height = 249
    Indent = 19
    TabOrder = 1
  end
  object Memo1: TMemo
    Left = 517
    Top = 24
    Width = 153
    Height = 249
    Lines.Strings = (
      'Memo1')
    TabOrder = 2
  end
  object Edit1: TEdit
    Left = 8
    Top = 315
    Width = 103
    Height = 21
    TabOrder = 3
    Text = 'Edit1'
    OnKeyPress = Edit1KeyPress
  end
  object Button1: TButton
    Left = 8
    Top = 384
    Width = 163
    Height = 25
    Caption = #1057#1086#1079#1076#1072#1090#1100' '#1080#1083#1080' '#1080#1079#1084#1077#1085#1080#1090#1100' '#1076#1077#1088#1077#1074#1086
    TabOrder = 4
    OnClick = Button1Click
  end
  object Button2: TButton
    Left = 594
    Top = 384
    Width = 108
    Height = 25
    Caption = #1054#1090#1086#1073#1088#1072#1079#1080#1090#1100' '#1076#1077#1088#1077#1074#1086
    TabOrder = 5
    OnClick = Button2Click
  end
  object Button3: TButton
    Left = 177
    Top = 384
    Width = 101
    Height = 25
    Caption = #1059#1076#1072#1083#1080#1090#1100' '#1076#1077#1088#1077#1074#1086
    TabOrder = 6
    OnClick = Button3Click
  end
  object Button4: TButton
    Left = 284
    Top = 384
    Width = 82
    Height = 25
    Caption = #1055#1088#1103#1084#1086#1081' '#1086#1073#1093#1086#1076
    TabOrder = 7
    OnClick = Button4Click
  end
  object Button5: TButton
    Left = 8
    Top = 342
    Width = 167
    Height = 25
    Caption = #1048#1079#1084#1077#1085#1080#1090#1100' '#1082#1086#1083#1080#1095#1077#1089#1090#1074#1086' '#1079#1072#1087#1080#1089#1077#1081
    TabOrder = 8
    OnClick = Button5Click
  end
  object Button6: TButton
    Left = 357
    Top = 342
    Width = 96
    Height = 25
    Caption = #1059#1076#1072#1083#1080#1090#1100' '#1101#1083#1077#1084#1077#1085#1090
    TabOrder = 9
    OnClick = Button6Click
  end
  object Edit2: TEdit
    Left = 357
    Top = 315
    Width = 96
    Height = 21
    TabOrder = 10
    Text = 'Edit2'
    OnKeyPress = Edit2KeyPress
  end
  object Button7: TButton
    Left = 372
    Top = 384
    Width = 94
    Height = 25
    Caption = #1054#1073#1088#1072#1090#1085#1099#1081' '#1086#1073#1093#1086#1076
    TabOrder = 11
    OnClick = Button7Click
  end
  object Button8: TButton
    Left = 472
    Top = 384
    Width = 116
    Height = 25
    Caption = #1057#1080#1084#1084#1077#1090#1088#1080#1095#1085#1099#1081' '#1086#1073#1093#1086#1076
    TabOrder = 12
    OnClick = Button8Click
  end
  object Edit3: TEdit
    Left = 217
    Top = 315
    Width = 96
    Height = 21
    TabOrder = 13
    Text = 'Edit3'
    OnKeyPress = Edit3KeyPress
  end
  object Button9: TButton
    Left = 217
    Top = 342
    Width = 96
    Height = 25
    Caption = #1053#1072#1081#1090#1080' '#1101#1083#1077#1084#1077#1085#1090
    TabOrder = 14
    OnClick = Button9Click
  end
  object Button10: TButton
    Left = 530
    Top = 344
    Width = 91
    Height = 25
    Caption = #1057#1073#1072#1083#1072#1085#1089#1080#1088#1086#1074#1072#1090#1100
    TabOrder = 15
    OnClick = Button10Click
  end
  object Button11: TButton
    Left = 530
    Top = 313
    Width = 133
    Height = 25
    Caption = #1053#1072#1081#1090#1080' '#1089#1083#1086#1074#1072' '#1085#1072' '#1073#1091#1082#1074#1091' '#39'a'#39
    TabOrder = 16
    OnClick = Button11Click
  end
  object Button12: TButton
    Left = 8
    Top = 424
    Width = 163
    Height = 25
    Caption = #1042#1099#1093#1086#1076
    TabOrder = 17
    OnClick = Button12Click
  end
end
