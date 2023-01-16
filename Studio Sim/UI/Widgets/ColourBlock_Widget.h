#pragma once
#ifndef COLOURBLOCK_WIDGET_H
#define COLOURBLOCK_WIDGET_H

#include "Widget.h"
#include "Transform.h"

class ColourBlock_Widget : public Widget
{
public:
    ColourBlock_Widget();
    ColourBlock_Widget( Colour colour, XMFLOAT2 pos, XMFLOAT2 size );
    ~ColourBlock_Widget();

    void Initialize( ID3D11Device* device, ID3D11DeviceContext* context, ConstantBuffer<Matrices>& mat );
    void Update( const float dt );
    void Draw( ID3D11Device* device, ID3D11DeviceContext* context, XMMATRIX worldOrtho );
    void Resolve( Colour colour, XMFLOAT2 pos, XMFLOAT2 size );

    inline std::shared_ptr<Sprite> GetSprite() const noexcept { return m_sprite; }
    inline std::shared_ptr<Transform> GetTransform() const noexcept { return m_transform; }

private:
    Colour m_colour;
    XMFLOAT2 m_vPosition, m_vSize;
    std::shared_ptr<Sprite> m_sprite;
    std::shared_ptr<Transform> m_transform;
};

#endif