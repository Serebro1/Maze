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

    public partial class Form1 : Form
    {
        GameNet gmNet;
        ControllerNet ctrl;
        private Label ExcepLab;
        private ShowHeroStatsNet viewStats;
        private ShowMazeView viewMaze;
        private ShowHeroView viewHero;
        private bool correctData()
        {
            if (int.TryParse(HeigText.Text, out _) && int.TryParse(WidthText.Text, out _) && int.TryParse(VisText.Text, out _))
            {
                return true;
            }
            return false;
        }
        public Form1()
        {
            InitializeComponent();
            KeyPreview = true;
            //KeyDown += new KeyEventHandler(Form1_KeyDown);
        }
        private void Form1_KeyPress(object sender, KeyPressEventArgs e)
        {
        }
        private void LoadViews()
        {
            viewStats = new ShowHeroStatsNet(gmNet, StatsPanel);
            viewMaze = new ShowMazeView(MazePanel);
            viewHero = new ShowHeroView(HeroPanel);
            gmNet.addObserver(viewStats);
            gmNet.addObserver(viewMaze);
            gmNet.addObserver(viewHero);
            
            StartBut.Enabled = false;
            FileSaveBut.Enabled = false;
            FileReadBut.Enabled = false;
            ExcepLab = new Label();
            ExcepLab.Dock = DockStyle.Fill;
            ExcepLab.ForeColor = Color.Red;
            ExcepLab.Font = new Font("Times New Roman", 16, FontStyle.Bold);
            ErrorPanel.Controls.Add(ExcepLab);
            gmNet.update();
        }
        private void StartBut_Click(object sender, EventArgs e)
        {
            if(correctData()) {
                gmNet = new GameNet(int.Parse(HeigText.Text), int.Parse(WidthText.Text), int.Parse(VisText.Text));
                ctrl = new ControllerNet(gmNet);
                LoadViews();
                ErrorLab.Visible = false;
                SaveLab.Visible = true;
            }
            else {
                ErrorLab.Text = "Введите корректно данные!";
                SaveLab.Visible = false;
                ErrorLab.Visible = true;
            }
        }

        private void FileSaveBut_Click(object sender, EventArgs e) // потом подумать
        {
            if(correctData()) {
                gmNet = new GameNet(int.Parse(HeigText.Text), int.Parse(WidthText.Text), int.Parse(VisText.Text));
                ctrl = new ControllerNet(gmNet);
                LoadViews();
                ErrorLab.Visible = false;
                SaveLab.Visible = true;
            }
            else
            {
                ErrorLab.Text = "Введите корректно данные!";
                SaveLab.Visible = false;
                ErrorLab.Visible = true;
            }
        }

        private void FileReadBut_Click(object sender, EventArgs e)
        {
            gmNet = new GameNet();
            ctrl = new ControllerNet(gmNet);
            LoadViews();
            ErrorLab.Visible = false;
            SaveLab.Visible = false;
        }

        private void Form1_KeyDown(object sender, KeyEventArgs e)
        {
            if (gmNet == null) return;
            try
            {
                ctrl.step((int)e.KeyCode);
                HeroPanel.Refresh();
                MazePanel.Refresh();
                ExcepLab.Text = "";
            }
            catch (ExZeroHpNet ex)
            {
                MessageBox.Show(ex.what(), "Defeat!", MessageBoxButtons.OK, MessageBoxIcon.Information);
                Close();
            }
            catch(ExWinNet ex)
            {
                MessageBox.Show(ex.what(), "Victory!", MessageBoxButtons.OK, MessageBoxIcon.Information);
                Close();
            }
            catch(ExWallHitNet ex)
            {
                ExcepLab.Text = ex.what();
                viewStats.event_m(gmNet);
            }
            catch(ExExitNet ex)
            {
                ExcepLab.Text = ex.what();
                viewStats.event_m(gmNet);
            }
            
        }

        private void MazePanel_Paint(object sender, PaintEventArgs e)
        {
            if (gmNet != null)
            {
                gmNet.update();
            }
        }
    }
}
