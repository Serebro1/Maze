using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace MazeNet
{
    public partial class MazeView : UserControl
    {
        GameNet obj;
        Pen p = new Pen(Color.Red, 1);
        public void init_model(GameNet _obj)
        {
            obj = _obj;
            obj.addObserver(new MazeNet(MazePanel));
        }
        class MazeNet : IObserverNet
        {
            Panel p;

            public MazeNet(Panel p)
            {
                this.p = p;
            }
            override public void event_m(GameNet gm)
            {
                p.Refresh();
            }

        }
        public MazeView()
        {
            InitializeComponent();
        }

        private void MazePanel_Paint(object sender, PaintEventArgs e)
        {
            //if (obj != null) obj.paint(e.Graphics, p);
        }

    }
}
