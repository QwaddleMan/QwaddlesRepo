/*

This is my first time learning the ropes of opengl. Everything in here is just practice code.
This may help some people in the future that happen to stumble upon this repo. enjoy

*/

#include <GL\glew.h>
#include <GLFW/glfw3.h>
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

#define JInt unsigned int

struct shaderSource {
	std::string vertexSource;
	std::string fragmentSource;
};

static shaderSource parseShader(const std::string & filepath)
{
	std::string line;
	std::ifstream file(filepath);

	enum class shaderType
	{
		NONE = -1, VERTEX = 0, FRAGMENT = 1
	};

	shaderType type = shaderType::NONE;
	std::stringstream ss[2];

	while (getline(file, line))
	{
		if (line.find("#shader") != std::string::npos)
		{
			if (line.find("vertex") != std::string::npos)
			{
				//vertex stuff
				type = shaderType::VERTEX;
			}
			else if (line.find("fragment") != std::string::npos)
			{
				//fragment stuff
				type = shaderType::FRAGMENT;
			}
		}
		else
		{
			ss[(int)type] << line << std::endl;
		}
	}


	file.close();

	return { ss[0].str(), ss[1].str() };
}

static unsigned int CompileShader(JInt type, const std::string & source)
{
	JInt id = glCreateShader(type);
	const char* src = source.c_str();
	glShaderSource(id, 1, &src, nullptr);
	glCompileShader(id);

	int result;
	glGetShaderiv(id, GL_COMPILE_STATUS, &result);
	

	if (result == GL_FALSE)
	{
		//no result means it failed to compile the shader
		int length;
		glGetShaderiv(id, GL_COMPILE_STATUS, &length);
		char* message = (char*)alloca(length * sizeof(char));
		
		//glGetShaderInfoLog(id, length, &length, message);

		std::cout << "could not compile shader!"<<std::endl;
		glDeleteShader(id);
		return 0;
	}

	return id;
}

static JInt CreateShader(const std::string & vertexShader, const std::string & fragmentShader)
{
	JInt program =  glCreateProgram();
	JInt vs = CompileShader(GL_VERTEX_SHADER, vertexShader);
	JInt fs = CompileShader(GL_FRAGMENT_SHADER, fragmentShader);

	glAttachShader(program, vs);
	glAttachShader(program, fs);
	glLinkProgram(program);
	glValidateProgram(program);

	glDeleteShader(vs);
	glDeleteShader(fs);

	return program;
}

int main(void)
{
	GLFWwindow* window;

	/* Initialize the library */
	if (!glfwInit())
		return -1;

	/* Create a windowed mode window and its OpenGL context */
	window = glfwCreateWindow(640, 480, "Qwaddles First Program", NULL, NULL);
	if (!window)
	{
		glfwTerminate();
		return -1;
	}
	
	
	/* Make the window's context current */
	glfwMakeContextCurrent(window);

	//initialize glew
	if (glewInit() != GLEW_OK)
		std::cout << "Glew could not be initialized!\n"; //must initialize glew after making the gl context

	float positions[] = {
		-0.5,  0.5,
		-0.5, -0.5,
		 0.5, -0.5,
		 0.5,  0.5,
	};

	unsigned int indecies[] {
		0, 1, 2, 0, 2, 3
	};

	std::cout << glGetString(GL_VERSION) << std::endl;

	unsigned int buffer;
	glGenBuffers(1, &buffer);                              //this is a vertex buffer for our vertecies
	glBindBuffer(GL_ARRAY_BUFFER, buffer);
	glBufferData(GL_ARRAY_BUFFER, 6*2 * sizeof(float), positions, GL_STATIC_DRAW);

	glEnableVertexAttribArray(0);						  //this tells opengl how to handle the vertecies
	glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, sizeof(float) * 2, 0);


	unsigned int ibo; //ibo stands for indecy buffer object
	glGenBuffers(1, &ibo);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ibo);			//this breaks the vertices down into elements so we don't have to declare the same vertecies multiple times
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, 6 * sizeof(unsigned int), indecies, GL_STATIC_DRAW);
	//here are out shader programs
	/*std::string vertexShader =
		"#version 330 core\n"
		"\n"
		"layout(location = 0) in vec4 position;\n"
		"\n"
		"void main()\n"
		"{\n"
		"	gl_Position = position;\n"
		"}\n";
												//this is how to write shaders as string

	std::string fragmentShader =
		"#version 330 core\n"
		"\n"
		"layout(location = 0) out vec4 color;\n"
		"\n"
		"void main()\n"
		"{\n"
		"	color = vec4(1.0,0.0,0.0,1.0);\n"
		"}\n";*/
	shaderSource shaders = parseShader("basic.shader");  //this takes in a file that has our shader program and parses it

	std::cout << shaders.vertexSource << std::endl;
	JInt shader = CreateShader(shaders.vertexSource,shaders.fragmentSource); // use the loaded shader
	glUseProgram(shader);

	/* Loop until the user closes the window */
	while (!glfwWindowShouldClose(window))//while the window is open do this stuff
	{
		/* Render here */
		glClear(GL_COLOR_BUFFER_BIT);  //clear the screen

		//draw a triangle
		//glDrawArrays(GL_TRIANGLES, 0, 6);
		glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, nullptr); //draw the elements

		
		/*
		//LEGACY
		glBegin(GL_TRIANGLES);
		glVertex2f(0.0f,   1.0f);
		glVertex2f(1.0f,  -1.0f);  //old legacy way to draw triangle
		glVertex2f(-1.0f, -1.0f);
		glEnd();
		*/


		/* Swap front and back buffers */
		glfwSwapBuffers(window);

		/* Poll for and process events */
		glfwPollEvents();
	}
	glDeleteProgram(shader);//delete out shader

	glfwTerminate();
	return 0;
}