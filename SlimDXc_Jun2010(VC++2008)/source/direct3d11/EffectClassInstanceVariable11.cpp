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

#include "../Utilities.h"
#include "../stack_array.h"

#include "Direct3D11Exception.h"

#include "EffectClassInstanceVariable11.h"

using namespace System;

namespace SlimDX
{
namespace Direct3D11
{ 
	EffectClassInstanceVariable::EffectClassInstanceVariable( ID3DX11EffectClassInstanceVariable* pointer )
	: EffectVariable( pointer )
	{
		m_Pointer = pointer;
	}
	
	EffectClassInstanceVariable::EffectClassInstanceVariable( IntPtr pointer )
	: EffectVariable( pointer )
	{
		m_Pointer = reinterpret_cast<ID3DX11EffectClassInstanceVariable*>( pointer.ToPointer() );
	}

	ClassInstance^ EffectClassInstanceVariable::ClassInstance::get()
	{
		ID3D11ClassInstance *result;

		HRESULT hr = m_Pointer->GetClassInstance(&result);
		if (RECORD_D3D11(hr).IsFailure)
			return nullptr;

		return SlimDX::Direct3D11::ClassInstance::FromPointer(result);
	}
}
}
