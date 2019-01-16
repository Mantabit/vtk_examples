#include <vtkSmartPointer.h>
#include <vtkChartXY.h>
#include <vtkContextScene.h>
#include <vtkContextView.h>
#include <vtkFloatArray.h>
#include <vtkPlotPoints.h>
#include <vtkRenderWindow.h>
#include <vtkRenderWindowInteractor.h>
#include <vtkRenderer.h>
#include <vtkTable.h>

#include <vtkConeSource.h>
#include <vtkPolyDataMapper.h>
#include <stdlib.h>

int main(int argc,char** argv){
	//create a cone surce
	vtkConeSource* cone=vtkConeSource::New();
	cone->SetHeight(3.0);
	cone->SetRadius(1.0);
	cone->SetResolution(100);
	
	//create a mapper
	vtkPolyDataMapper* coneMapper=vtkPolyDataMapper::New();
	coneMapper->SetInputConnection(cone->GetOutputPort());
	
	//create an actor
	vtkActor* coneActor=vtkActor::New();
	coneActor->SetMapper(coneMapper);
	
	//create a renderer and a render window
	vtkRenderer* ren1=vtkRenderer::New();
	ren1->AddActor(coneActor);
	ren1->SetBackground(1,1,1);

	vtkRenderWindow* renWin=vtkRenderWindow::New();
	renWin->AddRenderer(ren1);
	renWin->SetSize(300,300);
	
	//create a renderwindow interactor
	vtkRenderWindowInteractor* interactor=vtkRenderWindowInteractor::New();
	interactor->SetRenderWindow(renWin);
	
	renWin->Render();
	//interactor->Start();
	
	while(true){
	}
	
	return EXIT_SUCCESS;
}
