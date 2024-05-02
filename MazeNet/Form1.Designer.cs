namespace MazeNet
{
    partial class Form1
    {
        /// <summary>
        /// Обязательная переменная конструктора.
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        /// Освободить все используемые ресурсы.
        /// </summary>
        /// <param name="disposing">истинно, если управляемый ресурс должен быть удален; иначе ложно.</param>
        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        #region Код, автоматически созданный конструктором форм Windows

        /// <summary>
        /// Требуемый метод для поддержки конструктора — не изменяйте 
        /// содержимое этого метода с помощью редактора кода.
        /// </summary>
        private void InitializeComponent()
        {
            this.StatsPanel = new System.Windows.Forms.Panel();
            this.DungPanel = new System.Windows.Forms.Panel();
            this.HeroPanel = new System.Windows.Forms.Panel();
            this.FileSaveBut = new System.Windows.Forms.Button();
            this.StartBut = new System.Windows.Forms.Button();
            this.HeaderLab = new System.Windows.Forms.Label();
            this.DungLab = new System.Windows.Forms.Label();
            this.HeroLab = new System.Windows.Forms.Label();
            this.ErrorPanel = new System.Windows.Forms.Panel();
            this.ErrorLab = new System.Windows.Forms.Label();
            this.HeigText = new System.Windows.Forms.TextBox();
            this.HeigLab = new System.Windows.Forms.Label();
            this.WidLab = new System.Windows.Forms.Label();
            this.WidthText = new System.Windows.Forms.TextBox();
            this.LiveLab = new System.Windows.Forms.Label();
            this.textBox1 = new System.Windows.Forms.TextBox();
            this.FileReadBut = new System.Windows.Forms.Button();
            this.SaveLab = new System.Windows.Forms.Label();
            this.VisLab = new System.Windows.Forms.Label();
            this.VisText = new System.Windows.Forms.TextBox();
            this.SuspendLayout();
            // 
            // StatsPanel
            // 
            this.StatsPanel.BackColor = System.Drawing.SystemColors.Window;
            this.StatsPanel.BorderStyle = System.Windows.Forms.BorderStyle.FixedSingle;
            this.StatsPanel.Location = new System.Drawing.Point(246, 12);
            this.StatsPanel.Name = "StatsPanel";
            this.StatsPanel.Size = new System.Drawing.Size(542, 128);
            this.StatsPanel.TabIndex = 0;
            // 
            // DungPanel
            // 
            this.DungPanel.BackColor = System.Drawing.SystemColors.Window;
            this.DungPanel.BorderStyle = System.Windows.Forms.BorderStyle.FixedSingle;
            this.DungPanel.Location = new System.Drawing.Point(463, 143);
            this.DungPanel.Name = "DungPanel";
            this.DungPanel.Size = new System.Drawing.Size(324, 277);
            this.DungPanel.TabIndex = 1;
            // 
            // HeroPanel
            // 
            this.HeroPanel.BackColor = System.Drawing.SystemColors.Window;
            this.HeroPanel.BorderStyle = System.Windows.Forms.BorderStyle.FixedSingle;
            this.HeroPanel.Location = new System.Drawing.Point(247, 146);
            this.HeroPanel.Name = "HeroPanel";
            this.HeroPanel.Size = new System.Drawing.Size(206, 154);
            this.HeroPanel.TabIndex = 2;
            // 
            // FileSaveBut
            // 
            this.FileSaveBut.BackColor = System.Drawing.Color.FromArgb(((int)(((byte)(192)))), ((int)(((byte)(255)))), ((int)(((byte)(255)))));
            this.FileSaveBut.Font = new System.Drawing.Font("Microsoft Sans Serif", 10F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(204)));
            this.FileSaveBut.Location = new System.Drawing.Point(121, 245);
            this.FileSaveBut.Name = "FileSaveBut";
            this.FileSaveBut.Size = new System.Drawing.Size(91, 55);
            this.FileSaveBut.TabIndex = 3;
            this.FileSaveBut.Text = "Сохранить в файле";
            this.FileSaveBut.UseVisualStyleBackColor = false;
            this.FileSaveBut.Click += new System.EventHandler(this.FileSaveBut_Click);
            // 
            // StartBut
            // 
            this.StartBut.BackColor = System.Drawing.Color.FromArgb(((int)(((byte)(192)))), ((int)(((byte)(255)))), ((int)(((byte)(192)))));
            this.StartBut.Font = new System.Drawing.Font("Microsoft Sans Serif", 10F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(204)));
            this.StartBut.Location = new System.Drawing.Point(66, 184);
            this.StartBut.Name = "StartBut";
            this.StartBut.Size = new System.Drawing.Size(91, 55);
            this.StartBut.TabIndex = 4;
            this.StartBut.Text = "Старт";
            this.StartBut.UseVisualStyleBackColor = false;
            this.StartBut.Click += new System.EventHandler(this.StartBut_Click);
            // 
            // HeaderLab
            // 
            this.HeaderLab.AutoSize = true;
            this.HeaderLab.BackColor = System.Drawing.SystemColors.ActiveBorder;
            this.HeaderLab.Font = new System.Drawing.Font("Times New Roman", 20F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(204)));
            this.HeaderLab.Location = new System.Drawing.Point(29, 12);
            this.HeaderLab.Name = "HeaderLab";
            this.HeaderLab.Size = new System.Drawing.Size(182, 31);
            this.HeaderLab.TabIndex = 5;
            this.HeaderLab.Text = "Dungeon Zork";
            // 
            // DungLab
            // 
            this.DungLab.AutoSize = true;
            this.DungLab.Font = new System.Drawing.Font("Microsoft Sans Serif", 16F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(204)));
            this.DungLab.Location = new System.Drawing.Point(12, 53);
            this.DungLab.Name = "DungLab";
            this.DungLab.Size = new System.Drawing.Size(100, 26);
            this.DungLab.TabIndex = 6;
            this.DungLab.Text = "Dungeon";
            // 
            // HeroLab
            // 
            this.HeroLab.AutoSize = true;
            this.HeroLab.Font = new System.Drawing.Font("Microsoft Sans Serif", 16F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(204)));
            this.HeroLab.Location = new System.Drawing.Point(133, 53);
            this.HeroLab.Name = "HeroLab";
            this.HeroLab.Size = new System.Drawing.Size(59, 26);
            this.HeroLab.TabIndex = 7;
            this.HeroLab.Text = "Hero";
            // 
            // ErrorPanel
            // 
            this.ErrorPanel.BackColor = System.Drawing.SystemColors.Window;
            this.ErrorPanel.BorderStyle = System.Windows.Forms.BorderStyle.FixedSingle;
            this.ErrorPanel.Location = new System.Drawing.Point(247, 306);
            this.ErrorPanel.Name = "ErrorPanel";
            this.ErrorPanel.Size = new System.Drawing.Size(206, 114);
            this.ErrorPanel.TabIndex = 9;
            // 
            // ErrorLab
            // 
            this.ErrorLab.AutoSize = true;
            this.ErrorLab.Font = new System.Drawing.Font("Microsoft Sans Serif", 12F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(204)));
            this.ErrorLab.ForeColor = System.Drawing.Color.Red;
            this.ErrorLab.Location = new System.Drawing.Point(12, 303);
            this.ErrorLab.Name = "ErrorLab";
            this.ErrorLab.Size = new System.Drawing.Size(84, 20);
            this.ErrorLab.TabIndex = 8;
            this.ErrorLab.Text = "MenuError";
            this.ErrorLab.Visible = false;
            // 
            // HeigText
            // 
            this.HeigText.Location = new System.Drawing.Point(18, 104);
            this.HeigText.Name = "HeigText";
            this.HeigText.Size = new System.Drawing.Size(84, 20);
            this.HeigText.TabIndex = 10;
            this.HeigText.Text = "5";
            this.HeigText.TextAlign = System.Windows.Forms.HorizontalAlignment.Center;
            // 
            // HeigLab
            // 
            this.HeigLab.AutoSize = true;
            this.HeigLab.Font = new System.Drawing.Font("Microsoft Sans Serif", 10F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(204)));
            this.HeigLab.Location = new System.Drawing.Point(39, 84);
            this.HeigLab.Name = "HeigLab";
            this.HeigLab.Size = new System.Drawing.Size(49, 17);
            this.HeigLab.TabIndex = 11;
            this.HeigLab.Text = "Height";
            // 
            // WidLab
            // 
            this.WidLab.AutoSize = true;
            this.WidLab.Font = new System.Drawing.Font("Microsoft Sans Serif", 10F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(204)));
            this.WidLab.Location = new System.Drawing.Point(39, 126);
            this.WidLab.Name = "WidLab";
            this.WidLab.Size = new System.Drawing.Size(44, 17);
            this.WidLab.TabIndex = 12;
            this.WidLab.Text = "Width";
            // 
            // WidthText
            // 
            this.WidthText.Location = new System.Drawing.Point(18, 146);
            this.WidthText.Name = "WidthText";
            this.WidthText.Size = new System.Drawing.Size(84, 20);
            this.WidthText.TabIndex = 13;
            this.WidthText.Text = "5";
            this.WidthText.TextAlign = System.Windows.Forms.HorizontalAlignment.Center;
            // 
            // LiveLab
            // 
            this.LiveLab.AutoSize = true;
            this.LiveLab.Font = new System.Drawing.Font("Microsoft Sans Serif", 10F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(204)));
            this.LiveLab.Location = new System.Drawing.Point(145, 84);
            this.LiveLab.Name = "LiveLab";
            this.LiveLab.Size = new System.Drawing.Size(41, 17);
            this.LiveLab.TabIndex = 14;
            this.LiveLab.Text = "Lives";
            // 
            // textBox1
            // 
            this.textBox1.Location = new System.Drawing.Point(131, 104);
            this.textBox1.Name = "textBox1";
            this.textBox1.ReadOnly = true;
            this.textBox1.Size = new System.Drawing.Size(71, 20);
            this.textBox1.TabIndex = 15;
            this.textBox1.Text = "10";
            this.textBox1.TextAlign = System.Windows.Forms.HorizontalAlignment.Center;
            // 
            // FileReadBut
            // 
            this.FileReadBut.BackColor = System.Drawing.Color.FromArgb(((int)(((byte)(255)))), ((int)(((byte)(192)))), ((int)(((byte)(192)))));
            this.FileReadBut.Font = new System.Drawing.Font("Microsoft Sans Serif", 10F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(204)));
            this.FileReadBut.Location = new System.Drawing.Point(11, 245);
            this.FileReadBut.Name = "FileReadBut";
            this.FileReadBut.Size = new System.Drawing.Size(91, 55);
            this.FileReadBut.TabIndex = 16;
            this.FileReadBut.Text = "Извлечь из файла";
            this.FileReadBut.UseVisualStyleBackColor = false;
            this.FileReadBut.Click += new System.EventHandler(this.FileReadBut_Click);
            // 
            // SaveLab
            // 
            this.SaveLab.AutoSize = true;
            this.SaveLab.Font = new System.Drawing.Font("Microsoft Sans Serif", 10F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(204)));
            this.SaveLab.ForeColor = System.Drawing.Color.Cyan;
            this.SaveLab.Location = new System.Drawing.Point(104, 303);
            this.SaveLab.Name = "SaveLab";
            this.SaveLab.Size = new System.Drawing.Size(121, 17);
            this.SaveLab.TabIndex = 17;
            this.SaveLab.Text = "Карта сохранена";
            // 
            // VisLab
            // 
            this.VisLab.AutoSize = true;
            this.VisLab.Font = new System.Drawing.Font("Microsoft Sans Serif", 10F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(204)));
            this.VisLab.Location = new System.Drawing.Point(136, 127);
            this.VisLab.Name = "VisLab";
            this.VisLab.Size = new System.Drawing.Size(58, 17);
            this.VisLab.TabIndex = 18;
            this.VisLab.Text = "Visibility";
            // 
            // VisText
            // 
            this.VisText.Location = new System.Drawing.Point(130, 147);
            this.VisText.Name = "VisText";
            this.VisText.Size = new System.Drawing.Size(72, 20);
            this.VisText.TabIndex = 19;
            this.VisText.Text = "1";
            this.VisText.TextAlign = System.Windows.Forms.HorizontalAlignment.Center;
            // 
            // Form1
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.BackColor = System.Drawing.SystemColors.ActiveBorder;
            this.ClientSize = new System.Drawing.Size(800, 450);
            this.Controls.Add(this.VisText);
            this.Controls.Add(this.VisLab);
            this.Controls.Add(this.SaveLab);
            this.Controls.Add(this.FileReadBut);
            this.Controls.Add(this.textBox1);
            this.Controls.Add(this.LiveLab);
            this.Controls.Add(this.WidthText);
            this.Controls.Add(this.WidLab);
            this.Controls.Add(this.HeigLab);
            this.Controls.Add(this.HeigText);
            this.Controls.Add(this.ErrorPanel);
            this.Controls.Add(this.ErrorLab);
            this.Controls.Add(this.HeroLab);
            this.Controls.Add(this.DungLab);
            this.Controls.Add(this.HeaderLab);
            this.Controls.Add(this.StartBut);
            this.Controls.Add(this.FileSaveBut);
            this.Controls.Add(this.HeroPanel);
            this.Controls.Add(this.DungPanel);
            this.Controls.Add(this.StatsPanel);
            this.DoubleBuffered = true;
            this.Name = "Form1";
            this.Text = "Form1";
            this.KeyDown += new System.Windows.Forms.KeyEventHandler(this.Form1_KeyDown);
            this.KeyPress += new System.Windows.Forms.KeyPressEventHandler(this.Form1_KeyPress);
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.Panel StatsPanel;
        private System.Windows.Forms.Panel DungPanel;
        private System.Windows.Forms.Panel HeroPanel;
        private System.Windows.Forms.Button FileSaveBut;
        private System.Windows.Forms.Button StartBut;
        private System.Windows.Forms.Label HeaderLab;
        private System.Windows.Forms.Label DungLab;
        private System.Windows.Forms.Label HeroLab;
        private System.Windows.Forms.Panel ErrorPanel;
        private System.Windows.Forms.Label ErrorLab;
        private System.Windows.Forms.TextBox HeigText;
        private System.Windows.Forms.Label HeigLab;
        private System.Windows.Forms.Label WidLab;
        private System.Windows.Forms.TextBox WidthText;
        private System.Windows.Forms.Label LiveLab;
        private System.Windows.Forms.TextBox textBox1;
        private System.Windows.Forms.Button FileReadBut;
        private System.Windows.Forms.Label SaveLab;
        private System.Windows.Forms.Label VisLab;
        private System.Windows.Forms.TextBox VisText;
    }
}

