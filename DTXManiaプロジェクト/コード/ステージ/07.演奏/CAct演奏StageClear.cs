using DirectShowLib;
using System;
using System.Collections.Generic;
using System.Text;
using System.Drawing;
using FDK;

namespace DTXMania
{
	internal class CAct演奏StageClear : CActivity
	{
		// メソッド

		public void t開始()
		{
			this.counter = new CCounter( 0, 200, 5, CDTXMania.Timer );
		}
		public void t完了()
		{
			this.counter.n現在の値 = this.counter.n終了値;
		}

		// CActivity 実装

		public override void On非活性化()
		{
			if( !base.b活性化してない )
			{
				CDTXMania.tテクスチャの解放( ref this.tx描画用 );
                CDTXMania.t安全にDisposeする( ref this.dsStageClear );
				base.On非活性化();
			}
		}
		public override void OnManagedリソースの作成()
		{
			if( !base.b活性化してない )
			{
                this.tx描画用 = new CTexture( CDTXMania.app.Device, 1280, 720, CDTXMania.TextureFormat );
                this.dsStageClear = CDTXMania.t失敗してもスキップ可能なDirectShowを生成する( CSkin.Path( @"Graphics\7_StageClear.mp4" ), CDTXMania.app.WindowHandle, true, true );
				base.OnManagedリソースの作成();
			}
		}
		public override int On進行描画()
		{
			if( base.b活性化してない || ( this.counter == null ) )
			{
				return 0;
			}
            if( base.b初めての進行描画 )
            {
                CDTXMania.Skin.soundステージクリア音.t再生する();
                base.b初めての進行描画 = true;
            }
			this.counter.t進行();


			
			if( CDTXMania.Skin.soundステージクリア音.b再生中 )
			{
				return 0;
			}

            if( CDTXMania.Skin.soundステージクリア音 == null )
            {
                if( this.counter.b終了値に達した )
                {
                    return 1;
                }
            }
			return 1;
		}


		// その他

		#region [ private ]
		//-----------------
		private CCounter counter;
		private EFIFOモード mode;
		private CTexture tx白タイル64x64;
        private CTexture tx描画用;
        private CDirectShow dsStageClear;
		//-----------------
		#endregion
	}
}
