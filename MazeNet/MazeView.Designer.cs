namespace MazeNet
{
    partial class MazeView
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

        #region Код, автоматически созданный конструктором компонентов

        /// <summary> 
        /// Требуемый метод для поддержки конструктора — не изменяйте 
        /// содержимое этого метода с помощью редактора кода.
        /// </summary>
        private void InitializeComponent()
        {
            this.MazePanel = new System.Windows.Forms.Panel();
            this.SuspendLayout();
            // 
            // MazePanel
            // 
            this.MazePanel.BackColor = System.Drawing.SystemColors.Window;
            this.MazePanel.Location = new System.Drawing.Point(2, 1);
            this.MazePanel.Name = "MazePanel";
            this.MazePanel.Size = new System.Drawing.Size(324, 277);
            this.MazePanel.TabIndex = 0;
            this.MazePanel.Paint += new System.Windows.Forms.PaintEventHandler(this.MazePanel_Paint);
            // 
            // MazeView
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.Controls.Add(this.MazePanel);
            this.Name = "MazeView";
            this.ResumeLayout(false);

        }

        #endregion

        private System.Windows.Forms.Panel MazePanel;
    }
}
