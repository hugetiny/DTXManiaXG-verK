#include "stdafx.h"
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

#include <d3d10.h>

#include "Direct3D10Exception.h"

#include "Counter.h"
#include "CounterDescription.h"
#include "Device10.h"

using namespace System;

namespace SlimDX
{
namespace Direct3D10
{ 
	Counter::Counter( SlimDX::Direct3D10::Device^ device, CounterDescription description )
	{
		ID3D10Counter* counter = 0;
		D3D10_COUNTER_DESC nativeDescription = description.CreateNativeVersion();
		if( RECORD_D3D10( device->InternalPointer->CreateCounter( &nativeDescription, &counter ) ).IsFailure )
			throw gcnew Direct3D10Exception( Result::Last );
		
		Construct( counter );
	}

	CounterDescription Counter::Description::get()
	{
		D3D10_COUNTER_DESC description;
		InternalPointer->GetDesc( &description );
		return CounterDescription( description );
	}
}
}
