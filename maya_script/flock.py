import maya.cmds as cmds
import maya.OpenMaya as OM
import maya.OpenMayaAnim as OMA
import maya.cmds as cmds


##### Set Project File
m_projectDirectoryName=cmds.fileDialog2( caption="Please select directory for project", dialogStyle=2, fm=2)

class FlockTheSystem() :
	########################################################################################################################
	# @brief ctor
	########################################################################################################################

    def __init__(self) :
        # now we create a window ready to populate the components
        self.m_window = cmds.window( title='Flock The System', )
        # create a layout
        form = cmds.formLayout()
        tabs = cmds.tabLayout(innerMarginWidth=10, innerMarginHeight=10)
        cmds.formLayout( form, edit=True, attachForm=((tabs, 'top', 0), (tabs, 'left', 0), (tabs, 'bottom', 0), (tabs, 'right', 0)) )
        
        child1 = cmds.rowColumnLayout(numberOfColumns=1)
        #cmds.image( image='/home/i7867155/Desktop/Screenshot.png' )
        cmds.intFieldGrp( numberOfFields=2, label='Start Frame',  extraLabel='End Frame', value1=3, value2=3,  )
        #cmds.button( label='Update Flock', bgc=(1,0,0)  )
        #cmds.iconTextButton( style='iconOnly', image1='/home/i7867155/Desktop/Screenshot.png', command='click()' )
        
        

        exportButton = cmds.button( label='Export/Update Curves', command='exportCurves()' )


        cmds.setParent( tabs )

        child2 = cmds.rowColumnLayout(numberOfColumns=2)
        cmds.button(width=50)
        cmds.button()
        cmds.button()
        cmds.setParent( tabs )

        cmds.tabLayout( tabs, edit=True, tabLabel=((child1, 'Pre-flock'), (child2, 'Post-flock')) )
        
        # finally show the window
        cmds.showWindow( self.m_window )

def click():
    print 'button'
   
   
    
def exportCurves() :
	basicFilter = "*.curve"
	file=cmds.fileDialog2(caption="Please select file to save",fileFilter=basicFilter, dialogStyle=2)
	if file !="" :

		# get the currently selected objects and make sure we have only one object
		selected = OM.MSelectionList()
		OM.MGlobal.getActiveSelectionList(selected)
		selectedObjects = []
		selected.getSelectionStrings(selectedObjects)
		if len(selectedObjects) == 0 :
			cmds.confirmDialog( title='No objects Selected', message='Select one or more curves', button=['Ok'], defaultButton='Ok', cancelButton='Ok', dismissString='Ok' )
		else :
			ofile=open(file[0],'w')

			for object in selectedObjects :
				obj=OM.MObject( )
				selected.add(object)
				selected.getDependNode(0,obj)
				fn = OM.MFnTransform(obj)
				curve=""
				oChild = fn.child(0)
				if(oChild.apiTypeStr()=="kNurbsCurve") :
					print "got curve",object
					points=cmds.xform( (object+".cv[*]"), q=True, ws=True, t=True,os=True )
					ofile.write("Curve %s %d\n" %(object, len(points)/3)  )
					for n in range(0,len(points),3) :
						ofile.write("P %f %f %f \n" %(points[n],points[n+1],points[n+2]))
			ofile.close()
			
	
			





FlockTheSystem()