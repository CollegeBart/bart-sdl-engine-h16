using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Diagnostics;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using System.IO;

namespace EditorInterface
{
    public partial class Form1 : Form
    {
        private string projectName;
        public Form1()
        {
            InitializeComponent();
        }

        private void quitToolStripMenuItem1_Click(object sender, EventArgs e)
        {
            Application.Exit();
        }

        private void loadFoldersParser(OpenFileDialog openFileDialog1)
        {
         
            openFileDialog1.Filter = "Projects |*.engine";
            openFileDialog1.FilterIndex = 2;
            openFileDialog1.RestoreDirectory = true;

            if (openFileDialog1.ShowDialog() == DialogResult.OK)
            {
                projectName = Path.GetFileNameWithoutExtension(openFileDialog1.FileName);
                var d = new DirectoryInfo(Path.GetDirectoryName(openFileDialog1.FileName));
                label1.Text = d.Name;
            }
        }

        private void LoadScene(string name)
        {
            addSpritesToolStripMenuItem.Enabled = true;
            var d = new DirectoryInfo(name+@"\\Images");
            foreach (FileInfo fi in d.GetFiles())
                listBox1.Items.Add(fi.Name);
        }

        private void RefreshLstBox()
        {
            listBox1.Items.Clear();
        }
        private void openProjectToolStripMenuItem_Click(object sender, EventArgs e)
        {
            RefreshLstBox();
            OpenFileDialog openFileDialog1 = new OpenFileDialog();
            loadFoldersParser(openFileDialog1);
            LoadScene(Path.GetDirectoryName(openFileDialog1.FileName));
        }

        private void AddImageToFolder(string imgToLoad)
        {
            listBox1.BeginUpdate(); 
            listBox1.Items.Add(imgToLoad);
            listBox1.EndUpdate();
        }

        private void addImage(string imageToLoad)
        {
            if (imageToLoad != "")
            {
                listBox1.BeginUpdate();
                listBox1.Items.Add(imageToLoad);
                listBox1.EndUpdate();
            }
        }


        private void ShowImg(string ImgNum,string projectName)
        {
            Image img = Image.FromFile(Path.GetDirectoryName(Application.ExecutablePath) + @"\Component\Projects\" + projectName + @"\Images\" + ImgNum);
            pictureBox1.Image = img;
        }

        private void PutImgInLocalFolder(String path ,string name, string projectName)
        {
            string appPath = Path.GetDirectoryName(Application.ExecutablePath) + @"\Component\Projects\"+projectName+@"\Images\"+name;
            System.IO.File.Copy(path, appPath);
        }

        private void addSpritesToolStripMenuItem_Click(object sender, EventArgs e)
        {
            OpenFileDialog openFileDialog1 = new OpenFileDialog();
            openFileDialog1.Multiselect = false;
            if (openFileDialog1.ShowDialog() == DialogResult.OK)
            {
                PutImgInLocalFolder(openFileDialog1.FileName, Path.GetFileNameWithoutExtension(openFileDialog1.FileName),projectName);
                listBox1.Items.Add(Path.GetFileNameWithoutExtension(openFileDialog1.FileName));
                pictureBox1.Image = Image.FromFile(openFileDialog1.FileName);
            }

        }

        private void listBox1_Click(object sender, EventArgs e)
        {

        }

        private void pictureBox1_MouseClick(object sender, MouseEventArgs e)
        {

        }

        private void listBox1_MouseClick(object sender, MouseEventArgs e)
        {
            if (listBox1.Items.Count > 0)
            {
                int index = this.listBox1.IndexFromPoint(e.Location);
                if (index != System.Windows.Forms.ListBox.NoMatches)
                {
                    ShowImg(listBox1.Items[index].ToString(), projectName);
                }
            }
        }

        private void DeleteImages(string name)
        {
            pictureBox1.Image = null;
        }


        private void listBox1_KeyDown(object sender, KeyEventArgs e)
        {
            if (e.KeyCode == Keys.Delete)
            {
                DeleteImages(listBox1.SelectedItem.ToString());
                listBox1.Items.RemoveAt(listBox1.SelectedIndex);
            }
        }

        private void filesToolStripMenuItem1_Click(object sender, EventArgs e)
        {

        }
        private void button1_Click(object sender, EventArgs e)
        {
            
            OpenFileDialog openFileDialog1 = new OpenFileDialog();
            openFileDialog1.Filter = "Executable |*.exe";
            openFileDialog1.Multiselect = false;
            if (openFileDialog1.ShowDialog() == DialogResult.OK)
            {
                Process.Start(openFileDialog1.FileName);
            }
        }
    }
}
