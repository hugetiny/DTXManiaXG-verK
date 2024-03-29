/*
* Copyright (c) 2007-2010 SlimDX Group
* 
* Permission is hereby granted, free of charge, to any person obtaining a copy
* of this software and associated documentation files (the "Software"), to deal
* in the Software without restriction, including without limitation the rights
* to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
* copies of the Software, and to permit persons to whom the Software is
* furnished to do so, subject to the following conditions:
* 
* The above copyright notice and this permission notice shall be included in
* all copies or substantial portions of the Software.
* 
* THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
* IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
* FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
* AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
* LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
* OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
* THE SOFTWARE.
*/
#include "stdafx.h"

#include <d3d11.h>
#include <d3dx11.h>
#include <d3dx9.h>
#include <vcclr.h>
#include <cmath>

#include "Direct3D11Exception.h"

#include "Device11.h"
#include "SamplerState11.h"

using namespace System;

namespace SlimDX
{
namespace Direct3D11
{
	SamplerState^ SamplerState::FromDescription( Direct3D11::Device^ device, SamplerDescription description )
	{
		if( device == nullptr )
			throw gcnew ArgumentNullException( "device" );

		ID3D11SamplerState *sampler;
		D3D11_SAMPLER_DESC nativeDescription = description.CreateNativeVersion();

		if( RECORD_D3D11( device->InternalPointer->CreateSamplerState( &nativeDescription, &sampler ) ).IsFailure )
			return nullptr;

		return FromPointer( sampler );
	}

	SamplerDescription SamplerState::Description::get()
	{
		D3D11_SAMPLER_DESC desc;
		InternalPointer->GetDesc( &desc );

		return SamplerDescription( desc );
	}
}
}