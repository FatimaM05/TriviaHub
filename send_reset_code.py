import utils.transport
import utils.session
import smtplib  # need an smtp link to send the email so we need the smtp header file
from email.mime.multipart import MIMEMultipart  # mime just makes it easier to write emails cz it provides a built in body
from email.mime.text import MIMEText
import sys  # the arguments for the func below are passed directly into the cmd line terminal from the cpp file and we need the sys library to access the terminal so thats why this is here

def send_reset_email(recipient_email, reset_code):
    # Define the SMTP server credentials
    smtp_server = 'smtp.gmail.com'          # DO NOT CHANGE
    smtp_port = 587                         # DO NOT CHANGE
    username = 'junaidjaffery1@gmail.com'   # DO NOT CHANGE
    password = 'duvs dsej nzvc hhhx'        # DO NOT CHANGE

    # creating the message header using python lists
    msg = MIMEMultipart()
    msg['From'] = username
    msg['To'] = recipient_email
    msg['Subject'] = 'Password Reset Code'

    # creating the message body
    body = f'Your password reset code is: {reset_code}'

    # Attach the body to the email
    msg.attach(MIMEText(body, 'plain'))

    # Connect to the server
    server = smtplib.SMTP(smtp_server, smtp_port)
    server.starttls()

    try:
        # Login to the email account
        server.login(username, password)

        # Send the email
        server.send_message(msg)
        print("Email sent successfully!")

    except smtplib.SMTPAuthenticationError as e:
        print(f"Failed to authenticate with the SMTP server: {e}")

    except smtplib.SMTPRecipientsRefused as e:
        print(f"Recipient address refused: {e.recipients}")
        for recipient, error in e.recipients.items():
            print(f"Recipient: {recipient}, Error: {error}")

    except Exception as e:
        print(f"An error occurred: {e}")

    finally:
        # Disconnect from the server
        server.quit()

if __name__ == "__main__":
    recipient_email = sys.argv[1]
    reset_code = sys.argv[2]
    send_reset_email(recipient_email, reset_code)
