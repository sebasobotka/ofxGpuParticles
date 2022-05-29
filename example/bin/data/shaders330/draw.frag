#version 330

uniform sampler2DRect tex0;
in vec2 texCoordVarying;
in vec4 colorVarying;

out vec4 fragColor;

void main()
{
    //fragColor =  vec4(1.0, 1.0, 1.0, 0.1);
	fragColor = colorVarying;
	
	//fragColor =  gl_Color;
	//vec4 a = texture(tex0, texCoordVarying);
	//fragColor =  vec4(a.r, a.g, a.b, 0.1);
	//fragColor = texture(tex0, texCoordVarying);
}
