#include "impl.h"

using namespace TglImpl;

DECOMP_SIZE_ASSERT(Light, 0x4);
DECOMP_SIZE_ASSERT(LightImpl, 0x8);

// Inlined only
LightImpl::~LightImpl()
{
	if (m_data) {
		m_data->Release();
		m_data = NULL;
	}
}

// OFFSET: LEGO1 0x100a3770
void* LightImpl::ImplementationDataPtr()
{
	return reinterpret_cast<void*>(&m_data);
}

// OFFSET: LEGO1 0x100a3780
Result LightImpl::SetTransformation(const FloatMatrix4& matrix)
{
	D3DRMMATRIX4D helper;
	D3DRMMATRIX4D* d3dMatrix = Translate(matrix, helper);
	return ResultVal(m_data->AddTransform(D3DRMCOMBINE_REPLACE, *d3dMatrix));
}

// OFFSET: LEGO1 0x100a37e0
Result LightImpl::SetColor(float r, float g, float b)
{
	IDirect3DRMLightArray* lightArray;
	IDirect3DRMLight* light;
	m_data->GetLights(&lightArray);
	lightArray->GetElement(0, &light);
	return ResultVal(light->SetColorRGB(r, g, b));
}