#version 330

uniform mat4 modelViewProjectionMatrix;
uniform sampler2DRect particles0;
uniform sampler2DRect particles1;

in vec4  position;
in vec2  texcoord;

out vec2 texCoordVarying;
out vec4 colorVarying;

void main()
{
    texCoordVarying = texcoord;
	
	// i can pass color here
	//colorVarying = vec4(1.0,1.0,0.0,0.1);
		
	colorVarying = vec4(texture(particles0, texCoordVarying).rgb, 0.1);
		
    gl_Position = modelViewProjectionMatrix * vec4(texture(particles0, texCoordVarying).xyz, 1.0);
}
