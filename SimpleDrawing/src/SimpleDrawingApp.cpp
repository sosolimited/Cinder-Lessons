#include "cinder/app/AppNative.h"
#include "cinder/app/RendererGl.h"
#include "cinder/gl/gl.h"

using namespace ci;
using namespace ci::app;
using namespace std;

class SimpleDrawingApp : public AppNative {
public:
	void setup() override;
	void mouseDown( MouseEvent event ) override;
	void update() override;
	void draw() override;

	void drawPrimitive2DShapes();
	void drawPrimitive3DShapes();
private:

};

void SimpleDrawingApp::setup()
{
}

void SimpleDrawingApp::mouseDown( MouseEvent event )
{
}

void SimpleDrawingApp::update()
{
}

void SimpleDrawingApp::draw()
{
	// Colors are defined using normalized rgb by default.
	// This clears the drawing context to black.
	gl::clear( Color( 0, 0, 0 ) );

	// This will reset the color to whatever it was before when it falls out of scope.
	gl::ScopedColor color( Color( 1.0f, 1.0f, 0.0f ) );
	drawPrimitive2DShapes();

	gl::color( 0.0f, 1.0f, 1.0f );
	drawPrimitive3DShapes();
}

void SimpleDrawingApp::drawPrimitive2DShapes()
{

	gl::drawSolidCircle( vec2( 100, 100 ), 25.0f );

	gl::drawSolidRect( Rectf( 200, 100, 300, 200 ) );

	gl::drawLine( vec2( 100, 200 ), vec2( 200, 300 ) );

	gl::drawSolidTriangle( vec2( 100, 150 ), vec2( 150, 250 ), vec2( 50, 200 ) );
}

void SimpleDrawingApp::drawPrimitive3DShapes()
{
	// This will reset the matrices to whatever they were before when we leave this scope.
	gl::ScopedMatrices matrices;

	// Use a perspective projection.
	gl::setMatricesWindowPersp( getWindowSize(), 60.0f, 1.0f, 5000.0f );

	gl::enableDepthRead();
	gl::enableDepthWrite();

	gl::color( 1, 1, 1 );
	gl::rotate( M_PI * 0.1f, vec3( 0.1, 0.3, 0.5 ) );
	gl::drawCube( vec3( 500, 100, 0 ), vec3( 100 ) );
}

CINDER_APP_NATIVE( SimpleDrawingApp, RendererGl )
