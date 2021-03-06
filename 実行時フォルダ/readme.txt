///////////////////////////////////////////////
   
          DTXManiaXG(Ver.K) 4.00RC
 
///////////////////////////////////////////////
○概要
DTXManiaXG(Ver.K)をDTXMania Release104を元に作り直したものです。
一部コード書き直しにより、ほんの僅かながら内部処理が改善されているかもしれません。
.NET Frameworks 4に変更したため、Ver4.00からはWindowsXP環境では起動できません。

○諸注意
・現在は5レーンギター譜面に対応できていません。
・一部仕様については正式版リリースまでに変更が入る可能性があります。

○導入について
・絶対にVer3系までの環境に上書きをしないでください。
・スキンを含めて大きな変更が起こっているため、Ver3.60までの環境に上書きするのは大変危険です。

○Ver3.60までとの大きな変更点
・スクロール基準速度の変更
・フルスクリーン時の処理変更
・フォルダ構成の変更

○動画再生について
・従来のVideo for Windowsでの動画再生は廃止となりました。これによってDirectShowの環境構築が必須となっています。
・MemoryRendererシステムでの動画再生には対応していません。
・DirectShow環境の構築方法はDTXManiaのOSDN内Wikiに掲載されています。
　https://osdn.jp/projects/dtxmania/wiki/DirectShow%E5%AF%BE%E5%BF%9C%E3%81%AB%E3%81%A4%E3%81%84%E3%81%A6

○追加機能
・曲決定から演奏開始までの流れを変更。(曲決定演出→曲読み込み→演奏開始)
・簡易的に選曲画面で曲別スキルを表示できるようにした。
・X-PERFECT判定の実装。ただし判定数は通常のPERFECTに加算されます。有効にする場合はConfig.iniの「XPerfectJudgeMode」を1にしてください。
・レーン画像の描画方法を変更。これによって再現度が高くなりました。
・一部画像を大幅作り直し。
・レーンフラッシュのテクスチャ構造を見直すことで画像枚数の大幅削減に成功。
・スキルメーターの画像構造を変更。ギター2P側のレイアウトを再現。
・KONMAI式ソフトバージョン表示を採用。アップデートが適用されているかの確認、ビルド設定の確認が容易にできるようになった。(主に作者が得する)
・実行時フォルダをDTXManiaとDTXCreaterで統一。4.00からはDTXManiaとDTXCreaterの同一リリースになります。

○廃止
・100〜999によるXGレベル表記

○仕様
・X-PERFECTの判定範囲はPERFECT範囲の半分です。

○制約事項
・一部画像は製作中です。
・一部表示系のオプションは未実装です。
・ドラムランダム、レーン数変更、dkdk仕様変更は未実装です。
・ギターのコンボ表示に対応していません。
・FDK署名キーまわりの都合により、プラグイン側で参照するFDKとDTXMania側で参照するFDKが(ほぼ)同一でないとプラグインが読み込めなくなりました。
・旧規格クリップの表示は未対応です。
・リザルト画面のFC、EXC画像の描画に対応していません。
・FLIP機能は不具合があるため使用できません。
・DTXCreaterはギター5レーンに対応していません。

○連絡先
HP:http://dtxxgk.at-ninja.jp/
Mail:gennsou76573@gmail.com
Twitter:@kairera0467

○更新履歴
2016042700	リザルト画面のレベル数値表示に対応。
		Flipに対応。(YPボタンが無いため、現在はF5キーで切り替え可能)
		ギター演奏画面で、NamePlateTypeB時の難易度表示の整数部分のフォントサイズを大きめにした。
		ギター演奏画面パート表示が1P・2Pの両方で同じになっていたので修正。
		Wailingのチップ、枠表示に対応。(残りの2方向のWailingは実装できていないため作成を保留。)
		曲選択画面でアイテム数を表示できるようにした。
		不要な画像を読み込んでいたことにより、演奏開始できない状態になっていたので修正。
		DirectShow環境を構築していないなど、何らかの事情で動画ファイルの読み込みに失敗した場合、演奏中に一時停止をすると強制終了してしまう不具合を修正。
		リポジトリ内での実行時フォルダをDTXManiaとDTXCreaterで統一。
2016041100	スキルメーターの比較対象の達成率と、自己ベストの達成率が同じ数値の場合にパネルが重なって表示されてしまう不具合を修正。
		SkillModeがXGの場合でもランク計算がDTXManiaのままになっていたのを修正。
		曲決定演出時にDrumパートのパネルが表示されない不具合を修正。
		NamePlateTypeA時にCLASSIC譜面でなくても、CLASSIC譜面用のネームプレートが表示される不具合を修正。
2016040900	DTXCreaterを同梱してみる。
		ギターNamePlateTypeB時の曲名表示を実装。
		ドラム判定文字位置の再調整。リバース、TypeBに対応
		曲決定演出の難易度表示をドラムCLASSIC、ギター・ベースに対応。
		ボーナス演出時のレーン振動を仮実装。(Ver3.60までとコードが違います)
		タイトル画面でデバッグビルド状態であるかを確認できるようにした。
		DTXVモード時にLP・LBDがオートになっていなかったのを修正。
		RANDOM選択時に効果音が鳴っていなかったのを修正。
		CLASSIC譜面判別をデフォルトで有効にした。
		「ストイックモード」「BG Alpha」オプションの廃止。
		ギター画面のゲージが両方ともドラムの数値を参照していたので修正。
		ファイルからImage、CTextureを生成するメソッドを最適化。(try&catchをできるだけ使わないコードにした。NNAさんありがとうございます。)
2016032500	曲決定後の演出を実装。
		ギター画面の整理。
		ダークオプションの実装。
		CLASSIC譜面フラグの追加。
		難易度ラベルスクリプトをXG1用、XG2用の2つを同梱することにした。(暫定処置)
		ドラム判定文字位置の調整。(TypeAのみ)
		ギター判定文字位置の調整。(TypeA〜C、Reverse対応)
		選曲画面で曲パネル生成時に既にあるパネルを解放するようにした。
		演奏画面のデバッグ表示がズレていたので修正。
		タイトル画面、QuickConfigの操作がXGになっていなかったので修正。
		NameTypeB時の曲名表示がズレていたので修正。
2016030800	スキルメーターの対応開始
		NamePlateTypeの切り替え対応
		リザルトのゲージ画像追加
		リザルト画面の難易度ラベル、レベルの表示対応。
		CONFIG画面の項目フォントを少し小さめにした。
		スキンの検出に失敗していたのを修正。
2016030500	とりあえずRC版。