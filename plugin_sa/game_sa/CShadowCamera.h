#pragma once

#include "plbase/PluginBase.h"
#include "RenderWareTypes.h"

#pragma pack(push, 4)
class PLUGIN_API CShadowCamera
{
public:
	RwCamera *m_pRwCamera;
	RwTexture *m_pRwRenderTexture;

	CShadowCamera();
	~CShadowCamera();

	void CreateTexture();
	RwCamera *SetFrustum(float viewWindow);
	RwCamera *SetLight(RpLight *light);
	RwCamera *SetCenter(RwV3d *center);
	void InvertRaster();
	RwRaster *GetRwRenderRaster();
	RwTexture *GetRwRenderTexture();
	RwRaster *DrawOutlineBorder(RwRGBA  const& color);
	RwCamera *Create(int rasterSize);
	RwCamera *Update(RpClump *object);
	RwCamera *Update(RpAtomic *object);
	void MakeGradientRaster();
	RwImage *CreateRwImage();
	RwRaster *DrawBlurInRect(RwRect *rect);
	void RasterResample(RwRaster *raster);
	void RasterBlur(RwRaster *raster, int numPasses);
};
#pragma pack(pop)

VALIDATE_SIZE(CShadowCamera, 8);